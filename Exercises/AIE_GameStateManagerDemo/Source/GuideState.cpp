#include "GuideState.h"
#include "raylib.h"

#include "Application.h"

#include "GameStateManager.h"
#include "IGameState.h"

#include <iostream>

#include "GameMenuState.h"

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
	if (IsKeyPressed(KEY_M)) 
	{
		m_app->GetGameStateManager()->SetState("Guide", new GameMenuState(m_app));
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("GameMenu");
	}


}

void GuideState::Draw()
{
	DrawText("GuideState", 10, 10, 20, GRAY);
	DrawText("Press M to go back to Menu", 10, 50, 20, GRAY);





}