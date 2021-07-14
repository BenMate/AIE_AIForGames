#pragma once

#include "IGameState.h"

class Application;
class GameObject;

class PlayState : public IGameState
{

public:

	PlayState(Application* app);
	virtual ~PlayState();

	virtual void Load();
	virtual void Unload();

	virtual void Update(float deltaTime);
	virtual void Draw();


protected:

private:

	Application* m_app;

	GameObject* m_player1 = nullptr;
};