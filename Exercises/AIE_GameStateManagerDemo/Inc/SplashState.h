#pragma once

#include "IGameState.h"

class Application;

class SplashState : public IGameState
{

public:

	SplashState(Application* m_app);
	virtual ~SplashState();

	virtual void Load();
	virtual void Unload();

	virtual void Update(float deltaTime);
	virtual void Draw();


protected:

private:

	Application* m_app;

	float m_timer = 0.0f;

};