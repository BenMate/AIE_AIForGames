#pragma once

#include "IGameState.h"

class Application;

class Graph2D;
class Graph2DEditor;
class GameStateManager;


class DemoTwo : public IGameState
{

public:

	DemoTwo(Application* app);
	virtual ~DemoTwo();

	virtual void Load();
	virtual void Unload();

	virtual void Update(float deltaTime);
	virtual void Draw();


protected:

private:

	Application* m_app;

	GameStateManager* m_gameStateManager = nullptr;


	Graph2DEditor* m_graphEditor = nullptr;
	Graph2D* m_graph = nullptr;

};