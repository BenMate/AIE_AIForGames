#include "Demo1.h"
#include "raylib.h"

#include "Application.h"

#include "GameStateManager.h"
#include "IGameState.h"

#include "MenuState.h"

#include <iostream>
#include "Player.h"

DemoOne::DemoOne(Application* app) : m_app(app)
{
	

}

DemoOne::~DemoOne()
{
	
}


void DemoOne::Load()
{
	std::cout << "Loading DemoOne" << std::endl;

	m_player = new Player();
	m_player->SetPosition({ 800 * 0.25f , 600 / 2.0f }); //hard coded for now
	m_player->SetFriction(1.0f);

}

void DemoOne::Unload()
{
	std::cout << "Unloading DemoOne" << std::endl;

	delete m_player;
	m_player = nullptr;
}

void DemoOne::Update(float deltaTime)
{


	// only update if we are the top most state
	auto currentState = m_app->GetGameStateManager()->GetCurrentState();
	if (currentState != this)
		return;

	if (IsKeyPressed(KEY_SPACE)) m_app->GetGameStateManager()->PushState("Pause");
	
		
	if (IsKeyPressed(KEY_M)) 
	{
		m_app->GetGameStateManager()->SetState("Menu", new MenuState(m_app));
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("Menu");
	}

	m_player->Update(deltaTime);
}

void DemoOne::Draw()
{
	DrawText("Play", 10, 00, 50, GRAY);
	DrawText("Press 'M' to go back to Menu", 10, 100, 20, GRAY);


	m_player->Draw();
}