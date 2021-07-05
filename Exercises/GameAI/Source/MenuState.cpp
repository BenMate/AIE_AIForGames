#include "MenuState.h"
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


}

void MenuState::Draw()
{
	DrawText("Menu", 10, 100, 20, LIGHTGRAY);
}