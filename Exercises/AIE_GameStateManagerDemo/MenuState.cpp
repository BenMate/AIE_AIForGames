#include "MenuState.h"
#include "Application.h"
#include "GameStateManager.h"

#include "raylib.h"
#include <iostream>


MenuState::MenuState(Application* app) : m_app(app)
{


}

MenuState::~MenuState()
{

}


void MenuState::Load()
{
	std::cout << "Loading Menu" << std::endl;
}

void MenuState::Unload()
{
	std::cout << "Unloading Menu" << std::endl;
}

void MenuState::Update(float deltaTime)
{
	if (IsKeyPressed(KEY_P))
	{
		m_app->GetGameStateManager()->SetState("Menu", nullptr);
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("Play");
	}

	if (IsKeyPressed(KEY_G))
	{
		m_app->GetGameStateManager()->SetState("Menu", nullptr);
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("Graph");
	}

	if (IsKeyPressed(KEY_SPACE)) 
	{
		m_app->GetGameStateManager()->PushState("Pause");
	}

}

void MenuState::Draw()
{
	DrawText("Menu", 10, 5, 50, GRAY);

	DrawText("Press P to Play", 10, 200, 20, GRAY);
	DrawText("Press G for Graphs ", 10, 250, 20, GRAY);

	DrawText("Press Space to Pause", 10, 300, 20, GRAY);

}