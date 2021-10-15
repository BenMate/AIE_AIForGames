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
	CalculateSeekPath(obj);

	//TODO:
	// move object to first point in the path
	// create a function "ApplySeekForce(point)" that applies a force in the desired direction - see your seek demo for logic
	// 
	// check if we are within a radius from the targetPoint


	//if there is now a path to follow 
	if (m_path.empty() == false) 
	{
		//move target towards the first item in path
		ApplySeekForce(m_path.front(), obj);

		//check to see if we are inside the radius of the first item

		//if so apply seek force to the next target

	}


}

void GoblinSeekBehaviour::Draw(GameObject* obj)
{
	DrawCircle(m_target.x, m_target.y, m_targetRadius, LIGHTGRAY);
	DrawCircle(m_target.x, m_target.y, 5, GRAY);

	//todo:
	//draw circle of seeking path
}

void GoblinSeekBehaviour::CalculateSeekPath(GameObject* obj)
{
	// the path must be empty before we generate a new one.
	if (m_path.empty() == false)
		return;

	if (m_blackBoard->positionKnown == false) 	
		return;
	
	// Generate a new path	
	auto currentNode = m_graph->GetClosestNode(obj->GetPosition(), 20);
	auto endNode = m_graph->GetClosestNode(m_blackBoard->playersPos, 20);

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
	//TODO: fix
	
	//finds where the obj wants to go
	Vector2 heading = Vector2Add(obj->GetPosition(), obj->GetVelocity());
	float headingLen = Vector2Length(heading);
	
	//gets the direction of target
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
