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
	if (m_timer > 2.0f) 
	{
		m_app->GetGameStateManager()->SetState("Splash", nullptr);//sets splashstate to null - unloads it
		m_app->GetGameStateManager()->PopState(); //pops state off
		m_app->GetGameStateManager()->PushState("Menu"); //pushes a new state
	}
}

void SplashState::Draw() 
{
	DrawText("SplashState", 10, 12, 50, GRAY);
	DrawText("Loading Assets PLEASE WAIT...", 10, 250, 25, GRAY);
}