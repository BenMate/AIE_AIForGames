#include "Demo1.h"
#include "raylib.h"

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


}

void DemoOne::Draw()
{
	DrawText("Play", 10, 100, 20, GRAY);
}