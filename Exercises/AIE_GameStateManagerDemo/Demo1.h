#pragma once

#include "IGameState.h"

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

	Application* m_app;

	
	GameStateManager* m_gameStateManager = nullptr;

	Player* m_player = nullptr;

};