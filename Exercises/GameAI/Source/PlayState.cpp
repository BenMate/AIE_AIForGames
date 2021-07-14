#include "PlayState.h"
#include "raylib.h"
#include "Player.h"

#include "Application.h"
#include "GameStateManager.h"

#include <iostream>

PlayState::PlayState(Application* app) : m_app(app)
{


}

PlayState::~PlayState()
{

}


void PlayState::Load()
{
	std::cout << "Loading DemoOne" << std::endl;
}

void PlayState::Unload()
{
	std::cout << "Unloading DemoOne" << std::endl;
}

void PlayState::Update(float deltaTime)
{
	if (IsKeyPressed(KEY_SPACE))
	{
		m_app->GetGameStateManager()->PushState("Pause");
	}

	m_player1->Update(deltaTime);


}

void PlayState::Draw()
{
	DrawText("Play", 10, 100, 20, GRAY);

	m_player1->Draw();
}