#pragma once

#include "IGameState.h"

class GameStateManager;
class Application;


class GameOverState : public IGameState
{

public:

	GameOverState(Application* app);
	virtual ~GameOverState();

	virtual void Load();
	virtual void Unload();

	virtual void Update(float deltaTime);
	virtual void Draw();


protected:

private:

	Application* m_app;

	GameStateManager* m_gameStateManager = nullptr;

};