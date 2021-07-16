#include "Game.h"
#include "raylib.h"

#include "Application.h"

#include "GameStateManager.h"
#include "IGameState.h"

#include <iostream>


GameState::GameState(Application* app) : m_app(app)
{


}

GameState::~GameState()
{

}


void GameState::Load()
{


}

void GameState::Unload()
{
	
}

void GameState::Update(float deltaTime)
{
	
}

void GameState::Draw()
{
	DrawText("GameState", 10, 10, 20, GRAY);
}