#pragma once

#include "Behaviour.h"

class KeyBoardBehaviour : public Behaviour
{

public:

	KeyBoardBehaviour();
	KeyBoardBehaviour(int upKey, int downKey, int leftKey, int rightLey, float moveForce);
	virtual ~KeyBoardBehaviour();

	virtual void Update(GameObject* obj, float deltaTime);
	virtual void Draw(GameObject* obj);

protected:

	int m_upKey;
	int m_downKey;
	int m_leftKey;
	int m_rightKey;
	int m_BigboomKey;

	float m_moveForce = 0.0f;

private:
};