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
	if (IsKeyPressed(KEY_ONE))
	{
		m_app->GetGameStateManager()->SetState("Menu", nullptr);
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("Play");
	}

	if (IsKeyPressed(KEY_TWO))
	{
		m_app->GetGameStateManager()->SetState("Menu", nullptr);
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("Graph");
	}

	if (IsKeyPressed(KEY_P))
	{
		m_app->GetGameStateManager()->SetState("Menu", nullptr);
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("Game");
	}
}

void MenuState::Draw()
{
	DrawText("Menu", 10, 5, 50, GRAY);

	DrawText("Press 1 to Player Demo", 10, 200, 20, GRAY);
	DrawText("Press 2 for Graphs ", 10, 250, 20, GRAY);
	DrawText("Press P to Play Game", 10, 300, 20, DARKGRAY);


}