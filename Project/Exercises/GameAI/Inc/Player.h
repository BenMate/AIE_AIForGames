#pragma once

#include "GameObject.h"

class KeyBoardBehaviour;
class SeekBehaviour;
class FleeBehaviour;

class Player : public GameObject
{
public:

	Player();
	virtual ~Player();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	KeyBoardBehaviour* m_KbBehaviour;
	SeekBehaviour *m_seekBehaviour;
	FleeBehaviour* m_FleeBehaviour;

private:
};