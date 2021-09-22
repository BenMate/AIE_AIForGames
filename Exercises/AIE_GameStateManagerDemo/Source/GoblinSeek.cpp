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

	// TODO:
	// move object to first point in the path
	//	create a function "MoveToward(point)" that applies a force in the desired direction - see your seek demo for logic
	// check if we are within a radius from the targetPoint
	//


	//float distToTarget = Vector2Distance(obj->GetPosition(), m_blackBoard->playersPos);
	//if (distToTarget < m_targetRadius)
	//{
		//std::cout << " goblin hit player" << std::endl;		
	//}

	
}

void GoblinSeekBehaviour::Draw(GameObject* obj)
{
	DrawCircle(m_target.x, m_target.y, m_targetRadius, LIGHTGRAY);
	DrawCircle(m_target.x, m_target.y, 5, GRAY);
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

	for (auto& n : path)
	{
		m_path.push_back(n->data); //creates list of each node the path is created
	}

	//iter through the list
	m_iter = m_path.begin();

	SetTarget(*m_iter);

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
