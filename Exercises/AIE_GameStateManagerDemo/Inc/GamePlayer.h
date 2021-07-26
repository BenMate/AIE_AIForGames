#pragma once

#include "GameObject.h"

class KeyBoardBehaviour;
class SeekBehaviour;
class FleeBehaviour;

class GamePlayer : public GameObject
{
public:

	GamePlayer();
	virtual ~GamePlayer();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	KeyBoardBehaviour* m_KbBehaviour;
	SeekBehaviour* m_seekBehaviour;
	FleeBehaviour* m_FleeBehaviour;
	//pathfind 
	//wonder

private:
};