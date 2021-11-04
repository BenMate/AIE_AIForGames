#include "PatrolBehaviour.h"
#include "GameObject.h"

#include "Graph2D.h"
#include "BlackBoard.h"

#include "Graph.h"
#include "Graph2D.h"
#include "Graph2DEditor.h"

#include "raylib.h"
#include "Assets.h"

#include <vector>
#include <math.h>
#include <algorithm>
#include <iterator>

PatrolBehaviour::PatrolBehaviour(Graph2D* graph) : Behaviour()
{
	m_graph = graph;
	m_target = { 0,0 };
}

PatrolBehaviour::~PatrolBehaviour()
{

}

void PatrolBehaviour::Update(GameObject* obj, float deltaTime)
{
	CalculatePatrolPath(obj);

	if (m_patrolPath.empty() == false) 
	{
		int closestPoint = GetClosestPoint(m_patrolPath, obj->GetPosition());

		if (closestPoint + m_patrolPathDir >= m_patrolPath.size())
		{
			m_patrolPathDir = -1;
		}
		else if (closestPoint + m_patrolPathDir <= 0)
		{
			m_patrolPathDir = 1;
		}
		else
		{
			ApplyPatrolForce(m_patrolPath[closestPoint + m_patrolPathDir], obj);
		}

	}
}

void PatrolBehaviour::Draw(GameObject* obj)
{

}

void PatrolBehaviour::SetGraph(Graph2D* graph)
{
	m_graph = graph;
}

void PatrolBehaviour::CalculatePatrolPath(GameObject* obj)
{
	if (m_patrolPath.empty() == false)
		return;

	auto currentNode = m_graph->GetClosestNode(obj->GetPosition(), 30);
	
	//create a path using dijkstra
	auto path = m_graph->FindPath(IGraph::SearchType::DIJKSTRA, currentNode, [&](Graph<Vector2, float>::Node* n) {

		int tx = n->data.x / 32;
		int ty = n->data.y / 32;

		// get color on graph
		auto color = MyAssets::GetImagePixel(MyAssets::colourBGRaw, n->data.x, n->data.y);
		return color == 0xFF00FFFF;//yellow
		});

	//creates a list of each node
	for (auto pathNode : path)
	{
		m_patrolPath.push_back({ pathNode->data.x, pathNode->data.y });
	}

	m_iter = m_patrolPath.begin();

	SetTarget(*m_iter);
}

const Vector2& PatrolBehaviour::GetTarget() const
{
	return m_target;
}
void PatrolBehaviour::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& PatrolBehaviour::GetTargetRadius() const
{
	return m_targetRadius;
}

void PatrolBehaviour::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}

void PatrolBehaviour::OnArrive(std::function<void()> callback)
{
	m_onArriveFn = callback;
}

int PatrolBehaviour::GetClosestPoint(std::vector<Vector2> points, Vector2 target)
{
	float distance = 0;

	std::vector<int> arr;

	//updates a vector of distances
	for (int i = 0; i < points.size(); i++)
	{
		distance = sqrt(pow((points[i].x - target.x), 2) +
			pow((points[i].y - target.y), 2) * 1.0);

		arr.push_back(distance);
	}


	//returns the index of the smallest distance
	auto minDistanceIndex = std::min_element(arr.begin(), arr.end()) - arr.begin();
	return minDistanceIndex;
}

void PatrolBehaviour::ApplyPatrolForce(Vector2 target, GameObject* obj)
{
	//finds where the obj wants to go
	Vector2 heading = Vector2Add(obj->GetPosition(), obj->GetVelocity());
	float headingLen = Vector2Length(heading);

	//gets the direction of target	
	float distToTarget = Vector2Distance(target, obj->GetPosition());

	// assume if we are half a tile away from the target, than we have arrived.
	if (distToTarget < 16)
	{
		// we are at the target position - dont apply a force
		// also prevents divide by zero error if trying to normalise.
		return;
	}

	Vector2 dirToTarget = Vector2Normalize(Vector2Subtract(target, obj->GetPosition()));
	Vector2 vecToTarget = Vector2Scale(dirToTarget, headingLen);

	//adds force towards the target
	Vector2 targetForcePos = Vector2Add(vecToTarget, obj->GetPosition());
	Vector2 forceDir = Vector2Subtract(targetForcePos, heading);

	obj->ApplyForce(forceDir);
}
