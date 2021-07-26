#pragma once

#include "GameObject.h"

class SeekBehaviour;
class WanderBehaviour;

class GoblinWanderer : public GameObject
{
public:

	GoblinWanderer();
	virtual ~GoblinWanderer();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	
	SeekBehaviour* m_seekBehaviour;
	WanderBehaviour* m_wanderBehaviour;

private:
};