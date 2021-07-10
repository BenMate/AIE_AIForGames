#pragma once

#include "GameObject.h"
#include "IGameState.h"


class KeyBoardBehaviour;
class SeekBehaviour;
class FleeBehaviour;

class Application;

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

};