#pragma once

#include "IGameState.h"

class GameStateManager;
class Application;

class Button;
class BlackBoard;

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

	float m_windowWidth = 1600;
	float m_windowHeight = 900;

	Application* m_app;

	GameStateManager* m_gameStateManager = nullptr;

	Button* m_menuButton;

	BlackBoard* m_blackBoard = nullptr;
};