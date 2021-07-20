#include "Graph2D.h"

Graph2D::Graph2D()
{

}

Graph2D::~Graph2D()
{

}

void Graph2D::GetNearbyNodes(Vector2 position, float radius, std::vector<Graph2D::Node*>& out_nodes)
{
	for (auto& node : m_nodes) 
	{
		float r2 = radius * radius;
		Vector2 vec = { position.x - node->data.x, position.y - node->data.y };
		float dist = vec.x * vec.x + vec.y * vec.y;

		// float dist = Vector2Distance(position, node->data);
		if (dist < r2)
		{
			out_nodes.push_back(node);
		}
	}
}