#include "GameOverState.h"
#include "raylib.h"

#include "Application.h"

#include "GameStateManager.h"
#include "IGameState.h"

#include <iostream>

#include "GameMenuState.h"

GameOverState::GameOverState(Application* app) : m_app(app)
{

	std::cout << "Loading GameOverState" << std::endl;
}

GameOverState::~GameOverState()
{
	std::cout << "UnLoading GameOverState" << std::endl;
}


void GameOverState::Load()
{


}

void GameOverState::Unload()
{




}

void GameOverState::Update(float deltaTime)
{

	//takes you back to the Menu
	if (IsKeyPressed(KEY_M))
	{
		m_app->GetGameStateManager()->SetState("GameOver", new GameMenuState(m_app));
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("GameMenu");
	}


}

void GameOverState::Draw()
{
	DrawText("GameOverState", 10, 10, 20, GRAY);
}