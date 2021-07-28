#include "GameMenuState.h"
#include "Application.h"
#include "GameStateManager.h"

#include "raylib.h"
#include <iostream>

#include "MenuState.h"
#include "GameState.h"
#include "GuideState.h"

#include "Assets.h"

GameMenuState::GameMenuState(Application* app) : m_app(app)
{


}

GameMenuState::~GameMenuState()
{

}


void GameMenuState::Load()
{
	std::cout << "Loading GameMenuState" << std::endl;
}

void GameMenuState::Unload()
{
	std::cout << "Unloading GameMenuState" << std::endl;
}

void GameMenuState::Update(float deltaTime)
{
	//takes you to GuideState
	if (IsKeyPressed(KEY_ONE))
	{
		m_app->GetGameStateManager()->SetState("Menu", new GuideState(m_app));
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("Guide");
	}
	
	//takes you to GameState
	if (IsKeyPressed(KEY_P))
	{
		m_app->GetGameStateManager()->SetState("Menu", new GameState(m_app));
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("GameState");
	}
	//takes you back to the Testing Menu
	if (IsKeyPressed(KEY_TWO))
	{
		m_app->GetGameStateManager()->SetState("Menu", new MenuState(m_app));
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("Menu");
	}
}

void GameMenuState::Draw()
{

	DrawTexture(MyAssets::MenuBG, 0, 0, WHITE);

	DrawText("GameMenuState", 10, 5, 50, GRAY);

	DrawText("Press 1 to guide", 10, 100, 20, WHITE);
	DrawText("Press 2 for Tests", 10, 150, 20, WHITE);
	DrawText("Press P to Play Game", 10, 250, 20, WHITE);

	

}