#pragma once

#include "IGameState.h"

class Application;

class GraphState : public IGameState
{

public:

	GraphState(Application* app);
	virtual ~GraphState();

	virtual void Load();
	virtual void Unload();

	virtual void Update(float deltaTime);
	virtual void Draw();


protected:

private:

	Application* m_app;

};