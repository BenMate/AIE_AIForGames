#pragma once

#include "IGameState.h"

class Application;

class GameMenuState : public IGameState
{

public:

	GameMenuState(Application* app);
	virtual ~GameMenuState();

	virtual void Load();
	virtual void Unload();

	virtual void Update(float deltaTime);
	virtual void Draw();


protected:

private:

	Application* m_app;

};