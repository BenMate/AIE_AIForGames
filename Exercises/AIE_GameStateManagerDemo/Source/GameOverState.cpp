#include "GameOverState.h"
#include "raylib.h"

#include "Application.h"

#include "GameStateManager.h"
#include "IGameState.h"

#include <iostream>


GameOverState::GameOverState(Application* app) : m_app(app)
{


}

GameOverState::~GameOverState()
{

}


void GameOverState::Load()
{


}

void GameOverState::Unload()
{

}

void GameOverState::Update(float deltaTime)
{

}

void GameOverState::Draw()
{
	DrawText("GameOverState", 10, 10, 20, GRAY);
}