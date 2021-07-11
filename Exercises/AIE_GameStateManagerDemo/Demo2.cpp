#include "Demo2.h"
#include "raylib.h"

#include <iostream>

DemoTwo::DemoTwo(Application* app) : m_app(app)
{


}

DemoTwo::~DemoTwo()
{

}


void DemoTwo::Load()
{
	std::cout << "Loading DemoTwo" << std::endl;
}

void DemoTwo::Unload()
{
	std::cout << "Unloading DemoTwo" << std::endl;
}

void DemoTwo::Update(float deltaTime)
{


}

void DemoTwo::Draw()
{
	DrawText("Graph", 10, 100, 20, GRAY);
}