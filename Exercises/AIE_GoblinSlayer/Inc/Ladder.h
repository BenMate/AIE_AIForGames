#pragma once

#include "GameObject.h"

class LadderEntity : public GameObject
{
public:

	LadderEntity();
	virtual ~LadderEntity();

	virtual void Update(float deltaTime);
	virtual void Draw();

	void DrawLadder();
	bool IsNearLadder();

	float m_LadderRadius = 30.0f;

	bool PlayerEscaped = false;

protected:

	

private:
};