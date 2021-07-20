#include "GameState.h"
#include "raylib.h"

#include "Application.h"

#include "GameStateManager.h"
#include "IGameState.h"
#include "GameObject.h"

#include "Assets.h"

#include <iostream>

#include "Graph.h"
#include "Graph2D.h"
#include "Graph2DEditor.h"


GameState::GameState(Application* app) : m_app(app)
{

}

GameState::~GameState()
{

}


void GameState::Load()
{
	std::cout << "Loading GameState" << std::endl;

	m_camera.zoom = 1;
	m_camera.offset = { GetScreenWidth() / 2.0f ,GetScreenHeight() / 2.0f };

	MyAssets::LoadAssets();

	BuildGraphMap();
}

void GameState::Unload()
{
	std::cout << "UnLoading GameState" << std::endl;

	MyAssets::UnLoadAssets();
}

void GameState::Update(float deltaTime)
{
	// only update if we are the top most state
	auto currentState = m_app->GetGameStateManager()->GetCurrentState();
	if (currentState != this)
		return;

	if (IsKeyPressed(KEY_SPACE)) 
		m_app->GetGameStateManager()->PushState("Pause");
	
	UpdateGameCamera(deltaTime);

	for (auto chest : m_chest) 
	{
		chest->Update(deltaTime);
	}
		
	
	for (auto player : m_player) 
	{
		player->Update(deltaTime);
	}
		

}

void GameState::Draw()
{
	ClearBackground(WHITE);

	BeginMode2D(m_camera);

	DrawTexture(MyAssets::worldBG, 0, 0, WHITE);

	if (IsKeyDown(KEY_TAB)) DrawTexture(MyAssets::colourBG, 0, 0, WHITE);
	
	for (auto chest : m_chest)
	{
		chest->Draw();
	}

	for (auto player : m_player)
	{
		player->Draw();
	}
		
	

	DrawDebugGraph(); //comment out when finished

	DrawText("GameState", 10, 10, 100, DARKGRAY);

	EndMode2D();
}

void GameState::DrawDebugGraph() 
{
	for (auto& node : m_graph->GetNodes())
	{
		if (IsInCameraView(node->data)) 
		{
			DrawCircle(node->data.x, node->data.y, 4, GRAY); //draws nodes if its on the screen
		}
	}
}

unsigned int GameState::GetImagePixel(Image img, int xPos, int yPos) 
{
	unsigned int* data = (unsigned int*) img.data;
	unsigned int color = data[yPos * img.width + xPos];
	return color;	
}

void GameState::BuildGraphMap() 
{
	delete m_graph; 
	m_graph = new Graph2D(); 

	int numRows = MyAssets::worldBG.height / 16;
	int numCols = MyAssets::worldBG.width / 16;

	float xOffSet = 16;
	float yOffSet = 16;
	float spacing = 32;

	
	for (int y = 0; y < numRows; y++) 
	{
		for (int x = 0; x < numCols; x++)
		{
			float xPos = x * spacing + xOffSet;
			float yPos = y * spacing + yOffSet;
			auto color = GetImagePixel(MyAssets::colourBGRaw, xPos, yPos);


			//walkable space add a node
			if (color != 0xFF000000) 
			{
				m_graph->AddNode({ xPos, yPos });
			}
			//Spawns chest on red
			if (color == 0xFFFF0000) 
			{
				CreateChest({ xPos, yPos });
			}
			//spawn player on blue
			if (color == 0xFF0000FF)
			{
				CreatePlayer({ xPos, yPos });
			}

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
}

void GameState::UpdateGameCamera(float deltaTime) 
{
	if (IsKeyDown(KEY_W)) m_camera.target.y -= 200.0f * deltaTime;
	if (IsKeyDown(KEY_S)) m_camera.target.y += 200.0f * deltaTime;
	if (IsKeyDown(KEY_A)) m_camera.target.x -= 200.0f * deltaTime;
	if (IsKeyDown(KEY_D)) m_camera.target.x += 200.0f * deltaTime;

	int mouseScrollDelta = GetMouseWheelMove();
	m_camera.zoom += mouseScrollDelta * m_camera.zoom * 0.1f;

	if (m_camera.zoom < 0.2f)
	{
		m_camera.zoom = 0.2f;
	}
	
}

bool GameState::IsInCameraView(Vector2 pos)
{
	pos = GetWorldToScreen2D(pos, m_camera);
	return (!(pos.x < 0 || pos.x > GetScreenWidth() || pos.y < 0 || pos.y > GetScreenHeight()));
}

GameObject* GameState::CreateChest(Vector2 pos)
{
	GameObject* chest = new GameObject();
	chest->SetPosition(pos);

	m_chest.push_back(chest);
	return chest;
}

GameObject* GameState::CreatePlayer(Vector2 pos)
{
	GameObject* player = new GameObject();
	player->SetPosition(pos);
	m_player.push_back(player);
	return player;
}