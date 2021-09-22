#include "PatrolBehaviour.h"
#include "GameObject.h"

#include "Graph2D.h"
#include "BlackBoard.h"

#include "raylib.h"
#include "Assets.h"

#include <vector>


PatrolBehaviour::PatrolBehaviour() : Behaviour()
{
	m_target = { 0,0 };
}

PatrolBehaviour::~PatrolBehaviour()
{

}

void PatrolBehaviour::Update(GameObject* obj, float deltaTime)
{


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
	std::vector<Graph2D::Node*> nearbyNodes;

	m_graph->GetNearbyNodes(obj->GetPosition(), 20, nearbyNodes);


	auto startNode = nearbyNodes[0];

	auto path = m_graph->FindPath(IGraph::SearchType::DIJKSTRA, startNode, [&](Graph<Vector2, float>::Node* n) {

		int tx = n->data.x / 32;
		int ty = n->data.y / 32;

		// get color on graph
		auto color = MyAssets::GetImagePixel(MyAssets::colourBGRaw, n->data.x, n->data.y);
		return color == 0xFF00FFFF;//yellow
		});

	m_patrolPath.clear();
	for (auto pathNode : path)
	{
		m_patrolPath.push_back({ pathNode->data.x, pathNode->data.y });
	}
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