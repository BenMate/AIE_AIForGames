#pragma once

#include "IGameState.h"

class GameStateManager;
class Application;


class HighScoreState : public IGameState
{

public:

	HighScoreState(Application* app);
	virtual ~HighScoreState();

	virtual void Load();
	virtual void Unload();

	virtual void Update(float deltaTime);
	virtual void Draw();


protected:

private:

	Application* m_app;

	GameStateManager* m_gameStateManager = nullptr;

};