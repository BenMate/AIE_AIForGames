#pragma once

#include "GameObject.h"

class SeekBehaviour;
//class PathFind :TODO

class GoblinWanderer : public GameObject
{
public:

	GoblinWanderer();
	virtual ~GoblinWanderer();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:
	

	SeekBehaviour* m_seekBehaviour;
	//TODO: implement pathfind...

private:
};