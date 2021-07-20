#include "HighScoreState.h"
#include "raylib.h"

#include "Application.h"

#include "GameStateManager.h"
#include "IGameState.h"

#include <iostream>


HighScoreState::HighScoreState(Application* app) : m_app(app)
{


}

HighScoreState::~HighScoreState()
{

}


void HighScoreState::Load()
{

	std::cout << "Loading HighScoreState" << std::endl;
}

void HighScoreState::Unload()
{
	std::cout << "UnLoading HighScoreState" << std::endl;
}

void HighScoreState::Update(float deltaTime)
{

}

void HighScoreState::Draw()
{
	DrawText("HighScoreState", 10, 10, 20, GRAY);
	DrawText("Will be loading scores from file", 100, 100, 20, GRAY);
}