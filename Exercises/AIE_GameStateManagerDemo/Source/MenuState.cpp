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
		m_app->GetGameStateManager()->PushState("Agent");
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
		m_app->GetGameStateManager()->PushState("GameMenu");
	}
}

void MenuState::Draw()
{
	DrawText("DemoMenu", 10, 5, 50, GRAY);

	DrawText("Press 1 to agent tests", 10, 50, 20, GRAY);
	DrawText("Press 2 for Graph tests ", 10, 100, 20, GRAY);

	DrawText("Press P for GameMenu", 10, 150, 20, DARKGRAY);
}