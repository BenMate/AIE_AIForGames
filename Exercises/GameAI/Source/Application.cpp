#include "Application.h"
#include "raygui.h"
#include "Player.h"

#include "GameObject.h"
#include "KeyBoardBehaviour.h"

#include "Graph2D.h"
#include "Graph2DEditor.h"

#include "IGameState.h"



Application::Application(int windowWidth, int windowHeight, const char* windowTitle) :
	m_windowWidth(windowWidth),
	m_windowHeight(windowHeight),
	m_windowTitle(windowTitle)
{

}

Application::~Application()
{

}

void Application::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, m_windowTitle);
	SetTargetFPS(60);

	//loading in assets
	Load();

	//main game loop
	while (!WindowShouldClose())
	{
		float deltaTime = GetFrameTime();
		Update(deltaTime);
		Draw();
	}

	//unload assets
	UnLoad();

	//de-Initialization
	CloseWindow();
}

void Application::Load()
{
	m_player1 = new Player();
	m_player1->SetPosition({ m_windowWidth * 0.25f , m_windowHeight / 2.0f });
	m_player1->SetFriction(1.0f);

	//m_player1->SetBehaviour ( new SeekBehaviour()) ;
	//m_player->SetBehaviour ( new Fleeboardbehaviour()) ;

	//m_graph = new Graph2D();

	//int numRows = 4;
	//int numCols = 6;
	//float xOffSet = 100;
	//float yOffSet = 100;
	//float spacing = 50;

	//for (int y = 0; y < numRows; y++) {
	//	for (int x = 0; x < numCols; x++) {
	//		m_graph->AddNode({
	//			x * spacing + xOffSet,
	//			y * spacing + yOffSet
	//			});
	//	}
	//}

	//for (auto node : m_graph->GetNodes())
	//{
	//	std::vector<Graph2D::Node*> nearbyNodes;
	//	m_graph->GetNearbyNodes(node->data, 60, nearbyNodes);

	//	for (auto conncetedNode : nearbyNodes)
	//	{
	//		if (conncetedNode == node)
	//			continue;

	//		float dist = Vector2Distance(node->data, conncetedNode->data);
	//		m_graph->AddEdge(node, conncetedNode, dist);
	//		m_graph->AddEdge(conncetedNode, node, dist);
	//	}

	//}

	//m_graphEditor = new Graph2DEditor();
	//m_graphEditor->SetGraph(m_graph);
}

void Application::UnLoad()
{
	delete m_player1;
	m_player1 = nullptr;

	delete m_graphEditor;
	m_graphEditor = nullptr;


	delete m_graph;
	m_graph = nullptr;

	
}

void Application::Update(float deltaTime)
{
	m_player1->Update(deltaTime);

	//m_graphEditor->Update(deltaTime);

}

void Application::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	
	m_player1->Draw();
	//m_graphEditor->Draw();

	EndDrawing();
}
