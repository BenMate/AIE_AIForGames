#include "GoblinSeek.h"
#include "GameObject.h"

#include "Graph2D.h"
#include "BlackBoard.h"

#include "raylib.h"
#include "Assets.h"

#include <vector>

#include "Graph.h"
#include "Graph2D.h"
#include "Graph2DEditor.h"

#include <iostream>

#include <math.h>
#include <algorithm>
#include <iterator>


GoblinSeekBehaviour::GoblinSeekBehaviour(Graph2D* graph, BlackBoard* blackboard) : Behaviour()
{
	m_graph = graph;
	m_blackBoard = blackboard;
	m_target = { 0,0 };
}

GoblinSeekBehaviour::~GoblinSeekBehaviour()
{

}

void GoblinSeekBehaviour::Update(GameObject* obj, float deltaTime)
{
	//TODO: check if the goblin reaches the player and stop looping. 

	CalculateSeekPath(obj);	

	//if a path has been created 
	if (m_path.empty() == false)
	{
		int closestPoint = GetClosestPoint(m_path, obj->GetPosition());

		if (closestPoint + 1 >= m_path.size())
		{
			m_path.clear();
			return;
		}
		ApplySeekForce(m_path[closestPoint + 1], obj);
	
	}
}

void GoblinSeekBehaviour::Draw(GameObject* obj)
{
	//DrawCircle(m_target.x, m_target.y, m_targetRadius, GREEN);
	//DrawCircle(m_target.x, m_target.y, 5, GREEN);
}

void GoblinSeekBehaviour::CalculateSeekPath(GameObject* obj)
{
	// the path must be empty before we generate a new one.
	if (m_path.empty() == false)
		return;

	//if the blackboard doesnt know the players position then we cant create a path
	if (m_blackBoard->positionKnown == false) 	
		return;
	
	// Generate a new path	
	auto currentNode = m_graph->GetClosestNode(obj->GetPosition(), 30);
	auto endNode = m_graph->GetClosestNode(m_blackBoard->playersPos, 30);

	//creates a path using dijkstra
	auto path = m_graph->FindPath(IGraph::SearchType::DIJKSTRA, currentNode, [&](Graph<Vector2, float>::Node* n) {
		return n->data.x == endNode->data.x && n->data.y == endNode->data.y;
	});

	//creates list of each node the path is created
	for (auto& n : path)
	{
		m_path.push_back(n->data); 
	}

	//iter through the list
	m_iter = m_path.begin();

	SetTarget(*m_iter);
}

void GoblinSeekBehaviour::ApplySeekForce(Vector2 target, GameObject* obj) 
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

const Vector2& GoblinSeekBehaviour::GetTarget() const
{
	return m_target;
}

void GoblinSeekBehaviour::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& GoblinSeekBehaviour::GetTargetRadius() const
{
	return m_targetRadius;
}

void GoblinSeekBehaviour::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}

void GoblinSeekBehaviour::OnArrive(std::function<void()> callback)
{
	m_onArriveFn = callback;
}

void GoblinSeekBehaviour::SetGraph(Graph2D* graph)
{
	m_graph = graph;
}

int GoblinSeekBehaviour::GetClosestPoint(std::vector<Vector2> points, Vector2 target) 
{

	//float minDistance = 0;
	//int minIndex = 0;

	//for (int i = 0; i < points.size(); i++)
	//{
	//	auto dist = Vector2Distance(points[i], target);
	//	if (dist < minDistance)
	//	{
	//		minDistance = dist;
	//		minIndex = i;
	//	}
	//}

	//return minIndex;


	//TODO: Return index value of the point that is closest to the target.
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
