#include "SplashState.h"
#include "Application.h"
#include "GameStateManager.h"

#include <iostream>
#include "raylib.h"


SplashState::SplashState(Application* app) : m_app(app)
{

}

SplashState::~SplashState()
{

}

void SplashState::Load()
{
	std::cout << "Loading Splash" << std::endl;
}

void SplashState::Unload()
{
	std::cout << "Unload Splash" << std::endl;
}

void SplashState::Update(float deltaTime)
{
	m_timer += deltaTime;
	if (m_timer > 3.0f)
	{
		m_app->GetGameStateManager()->SetState("Splash", nullptr);//unloads
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("Menu");
	}
}

void SplashState::Draw()
{
	DrawText("Splash", 10, 10, 20, LIGHTGRAY);
}