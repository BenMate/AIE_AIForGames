#include "GraphState.h"
#include "raylib.h"

#include <iostream>

GraphState::GraphState(Application* app) : m_app(app)
{


}

GraphState::~GraphState()
{

}


void GraphState::Load()
{
	std::cout << "Loading Graphs" << std::endl;

}

void GraphState::Unload()
{
	std::cout << "Unloading Graphs" << std::endl;
}

void GraphState::Update(float deltaTime)
{


}

void GraphState::Draw()
{
	DrawText("Graph State", 10, 5, 50, GRAY);
}