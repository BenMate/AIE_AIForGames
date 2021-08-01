#include "GameOverState.h"
#include "raylib.h"

#include "Application.h"

#include "GameStateManager.h"
#include "IGameState.h"
#include "GameMenuState.h"

#include "Button.h"
#include "BlackBoard.h"

#include <iostream>
#include <string>



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
	m_menuButton = new Button({ m_windowWidth / 10  , m_windowHeight / 5 }, { 400, 175 }, "Menu", 50, GRAY, DARKGRAY, WHITE);

	m_menuButton->SetOnButtonClick([&](auto n) {
		m_app->GetGameStateManager()->SetState("GameOver", new GameMenuState(m_app));
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("GameMenu");
		});
}

void GameOverState::Unload()
{


}

void GameOverState::Update(float deltaTime)
{
	m_menuButton->Update(deltaTime);

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
	/*int score = m_blackboard->score;

	std::string str = std::to_string(score);
	char const* pchar = str.c_str();
	DrawText(pchar, 20, 20, 20, BLACK);*/

	DrawText("GameOverState", 100, 100, 50, GRAY);

	m_menuButton->Draw();

}