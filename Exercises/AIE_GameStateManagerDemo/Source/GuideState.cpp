#include "GuideState.h"
#include "raylib.h"

#include "Application.h"

#include "GameStateManager.h"
#include "IGameState.h"

#include <iostream>


GuideState::GuideState(Application* app) : m_app(app)
{


}

GuideState::~GuideState()
{

}


void GuideState::Load()
{

	std::cout << "Loading GuideState" << std::endl;
}

void GuideState::Unload()
{
	std::cout << "UnLoading GuideState" << std::endl;
}

void GuideState::Update(float deltaTime)
{

}

void GuideState::Draw()
{
	DrawText("GuideState", 10, 10, 20, GRAY);
}