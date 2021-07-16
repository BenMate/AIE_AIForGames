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
	DrawText("SplashScreen", 10, 15, 25, GRAY);

	DrawText("Loading...Program....", 10 ,100 , 20, GRAY);

	if (m_timer > 1.9f) DrawText("Complete", 200, 100, 20, GRAY);
	

}