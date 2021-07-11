#pragma once

#include "IGameState.h"

class Application;

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

};