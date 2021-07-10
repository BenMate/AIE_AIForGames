#include "Player.h"

#include "KeyBoardBehaviour.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"

#include "PlayState.h"
#include "Application.h"

#include "GameStateManager.h"

#include "IGameState.h"
#include "GameObject.h"

#include "raylib.h"
#include <iostream>

PlayState::PlayState(Application* app) : m_app(app)
{


}

PlayState::~PlayState()
{

}


void PlayState::Load()
{
	std::cout << "Loading Play" << std::endl;

}

void PlayState::Unload()
{
	std::cout << "Unloading Play" << std::endl;
}

void PlayState::Update(float deltaTime)
{
	if (IsKeyPressed(KEY_P)) //Press p to pause
	{   
		//m_app->GetGameStateManager()->PushState("Pause"); 
		//-- overlays on the screen the pause state -- then to unpause popoff pause --
	}

}

void PlayState::Draw()
{
	DrawText("Play State", 10, 5, 50, GRAY);

	//everything to do with behavours and the player add here

	

}