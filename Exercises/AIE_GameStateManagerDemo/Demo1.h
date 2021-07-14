#pragma once

#include "IGameState.h"

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

	Player* m_player;
};