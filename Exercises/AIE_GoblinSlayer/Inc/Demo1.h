#pragma once

#include "IGameState.h"

//being declared
class GameStateManager;
class Application;
class Player;

class DemoOne : public IGameState
{

public:

	DemoOne(Application* app);
	virtual ~DemoOne();

	virtual void Load();
	virtual void Unload();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:


private:

	int m_windowHeight = 800;
	int m_windowWidth = 600;

	Application* m_app;
	GameStateManager* m_gameStateManager = nullptr;
	Player* m_player = nullptr;

};