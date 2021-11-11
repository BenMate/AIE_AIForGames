#include "Demo2.h"
#include "raylib.h"

#include "Application.h"

#include "GameStateManager.h"
#include "IGameState.h"

#include "MenuState.h"

#include <iostream>
#include "Graph.h"
#include "Graph2D.h"
#include "Graph2DEditor.h"

DemoTwo::DemoTwo(Application* app) : m_app(app)
{

}

DemoTwo::~DemoTwo()
{

}

void DemoTwo::Load()
{
	std::cout << "Loading DemoTwo" << std::endl;

	m_graph = new Graph2D();

	int numRows = 4;
	int numCols = 6;
	float xOffSet = 100;
	float yOffSet = 100;
	float spacing = 50;

	for (int y = 0; y < numRows; y++) {
		for (int x = 0; x < numCols; x++) {
			m_graph->AddNode({
				x * spacing + xOffSet,
				y * spacing + yOffSet
				});
		}
	}

	for (auto node : m_graph->GetNodes())
	{
		std::vector<Graph2D::Node*> nearbyNodes;
		m_graph->GetNearbyNodes(node->data, 60, nearbyNodes);

		for (auto conncetedNode : nearbyNodes)
		{
			if (conncetedNode == node)
				continue;

			float dist = Vector2Distance(node->data, conncetedNode->data);
			m_graph->AddEdge(node, conncetedNode, dist);
			m_graph->AddEdge(conncetedNode, node, dist);
		}

	}

	m_graphEditor = new Graph2DEditor();
	m_graphEditor->SetGraph(m_graph);
}

void DemoTwo::Unload()
{
	std::cout << "Unloading DemoTwo" << std::endl;

	delete m_graphEditor;
	m_graphEditor = nullptr;


	delete m_graph;
	m_graph = nullptr;
}

void DemoTwo::Update(float deltaTime)
{
	if (IsKeyPressed(KEY_SPACE)) m_app->GetGameStateManager()->PushState("Pause");

	if (IsKeyPressed(KEY_M))
	{
		m_app->GetGameStateManager()->SetState("Menu", new MenuState(m_app));
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("Menu");
	}

	m_graphEditor->Update(deltaTime);
}

void DemoTwo::Draw()
{
	DrawText("Demo 2", 10, 1, 50, GRAY);
	DrawText("Press M to go back", 10, 50, 20, GRAY);
	
	m_graphEditor->Draw();
}