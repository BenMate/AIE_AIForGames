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

#include "Player.h"
#include "MainCharacter.h"


GameState::GameState(Application* app) : m_app(app)
{

}

GameState::~GameState()
{

}

void GameState::Load()
{
	std::cout << "Loading GameState" << std::endl;

	MyAssets::LoadAssets();

	m_camera.zoom = 1;
	m_camera.offset = { GetScreenWidth() / 2.0f ,GetScreenHeight() / 2.0f };

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

	m_mainCharacter->Update(deltaTime);


	/*for (auto chest : m_chest) 
	{
		chest->Update(deltaTime);
	}*/
	
		
	/*for (auto goblin : m_goblin)
	{
		goblin->Update(deltaTime);
	}*/

}

void GameState::Draw()
{
	ClearBackground(WHITE);

	BeginMode2D(m_camera);

	DrawTexture(MyAssets::worldBG, 0, 0, WHITE);

	if (IsKeyDown(KEY_TAB)) DrawTexture(MyAssets::colourBG, 0, 0, WHITE);
	
	//for (auto chest : m_chest)
	//{
	//	chest->Draw();
	//	
	//}

		m_mainCharacter->Draw(); 

	//for (auto goblin : m_goblin) 
	//{
	//	goblin->Draw();
	//}
		
	if (IsKeyDown(KEY_TAB)) DrawDebugGraph();

	DrawText("GameState", 10, 10, 100, DARKGRAY);

	EndMode2D();
}

void GameState::DrawDebugGraph() 
{
	for (auto& node : m_graph->GetNodes())
	{
		if (IsInCameraView(node->data)) 
		{
			DrawCircle(node->data.x, node->data.y, 4, GRAY); //only draws if its on the players screen
		}
	}
}



void GameState::BuildGraphMap() 
{
	delete m_graph; 
	m_graph = new Graph2D(); 

	float xOffSet = 16;
	float yOffSet = 16;
	float spacing = 32;

	int numRows = MyAssets::worldBG.height / spacing;
	int numCols = MyAssets::worldBG.width / spacing;

	for (int y = 0; y < numRows; y++) 
	{
		for (int x = 0; x < numCols; x++)
		{
			float xPos = (x * spacing) + xOffSet;
			float yPos = (y * spacing) + yOffSet;
			auto color = MyAssets::GetImagePixel(MyAssets::colourBGRaw, xPos, yPos);

			//spawns node on a walkable space
			if (color != 0xFF000000)
			{
				m_graph->AddNode({ xPos, yPos });
			}

			//Spawns chest on red
			/*if (color == 0xFF0000FF)
			{
				CreateChest({ xPos, yPos });
			}*/

			//spawn player on blue 
			if (color == 0xFFFF0000)
			{
				CreatePlayer({ xPos, yPos });
			}

			//spawn goblin on green
			/*if (color == 0xFF00FF00)
			{
				CreateGoblin({xPos, yPos});
			}*/
			
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
	int mouseScrollDelta = GetMouseWheelMove();
	m_camera.zoom += mouseScrollDelta * m_camera.zoom * 0.05f;

	if (m_camera.zoom < 0.2f) m_camera.zoom = 0.2f;
	m_camera.target = m_mainCharacter->GetPosition();
}

bool GameState::IsInCameraView(Vector2 pos)
{
	pos = GetWorldToScreen2D(pos, m_camera);
	return (!(pos.x < 0 || pos.x > GetScreenWidth() || pos.y < 0 || pos.y > GetScreenHeight()));
}

//
//GameObject* GameState::CreateChest(Vector2 pos)
//{
//	GameObject* chest = new GameObject();
//	chest->SetPosition(pos);
//
//	m_chest.push_back(chest);
//	return chest;
//}

GameObject* GameState::CreatePlayer(Vector2 pos)
{
	m_mainCharacter = new MainCharacter();//create new gameobject - mainCharacter
	m_mainCharacter->SetPosition(pos);//sets its initial pos

	return m_mainCharacter;
}

//GameObject* GameState::CreateGoblin(Vector2 pos) 
//{
//	GameObject* goblin = new GameObject();//make file
//	goblin->SetPosition(pos);
//
//	m_goblin.push_back(goblin);
//	return goblin;
//}

void GameState::UpdateColRec() 
{
	int tilesize = 32;
//	auto playerPos = m_player->GetPosition();



}

void GameState::DrawColRec() 
{

}

