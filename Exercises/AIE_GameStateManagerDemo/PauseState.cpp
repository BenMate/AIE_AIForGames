#include "PauseState.h"
#include "Application.h"
#include "GameStateManager.h"

#include "raylib.h"
#include <iostream>


PauseState::PauseState(Application* app) : m_app(app)
{


}

PauseState::~PauseState()
{

}


void PauseState::Load()
{
	std::cout << "Loading Pause" << std::endl;
}

void PauseState::Unload()
{
	std::cout << "Unloading Pause" << std::endl;
}

void PauseState::Update(float deltaTime)
{
	if (IsKeyPressed(KEY_SPACE))
	{
		m_app->GetGameStateManager()->PopState();
		//how to actually pop the state off


	}
}

void PauseState::Draw()
{
	DrawText("Paused...", 100, 100, 30, GRAY);
}