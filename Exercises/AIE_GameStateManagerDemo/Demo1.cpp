#include "Demo1.h"
#include "raylib.h"

#include "Application.h"
#include "GameStateManager.h"

#include <iostream>

DemoOne::DemoOne(Application* app) : m_app(app)
{


}

DemoOne::~DemoOne()
{

}


void DemoOne::Load()
{
	std::cout << "Loading DemoOne" << std::endl;
}

void DemoOne::Unload()
{
	std::cout << "Unloading DemoOne" << std::endl;
}

void DemoOne::Update(float deltaTime)
{
	if (IsKeyPressed(KEY_SPACE))
	{
		m_app->GetGameStateManager()->PushState("Pause");
	}

}

void DemoOne::Draw()
{
	DrawText("Play", 10, 100, 20, GRAY);
}