#include "GuideState.h"
#include "raylib.h"

#include "Application.h"

#include "GameStateManager.h"
#include "IGameState.h"

#include <iostream>

#include "GameMenuState.h"

GuideState::GuideState(Application* app) : m_app(app)
{


}

GuideState::~GuideState()
{

}


void GuideState::Load()
{

	std::cout << "Loading GuideState" << std::endl;
}

void GuideState::Unload()
{
	std::cout << "UnLoading GuideState" << std::endl;
}

void GuideState::Update(float deltaTime)
{
	if (IsKeyPressed(KEY_M)) 
	{
		m_app->GetGameStateManager()->SetState("Guide", new GameMenuState(m_app));
		m_app->GetGameStateManager()->PopState();
		m_app->GetGameStateManager()->PushState("GameMenu");
	}
}

void GuideState::Draw()
{
	DrawText("GuideState", 10, 10, 20, GRAY);
	DrawText("Press M to go back to Menu", 10, 50, 20, GRAY);

	DrawText("Controls!", 10, 100, 30, DARKGRAY);
	DrawText("Press t to quit", 10, 125, 20, GRAY);
	DrawText("Press space to pause", 10 , 150, 20 , GRAY);
	DrawText("Press W, A, S, D to mode", 10, 175, 20, GRAY);
	DrawText("Hold Tab to show dev move", 10, 200, 20, GRAY);
	
	DrawText("Gameplay!", 10, 240, 30, DARKGRAY);
	DrawText("Try to Remain hidden! If you're caught, you lose!", 10, 275, 20, RED);
	DrawText("Collect your gold back from chests and leave.", 10, 300, 20, GRAY);
	DrawText("You dropped your sword on the way down and it broke ", 10, 325, 20, GRAY);
	DrawText("So you cant fight back :(", 10, 350, 20, GRAY);

}