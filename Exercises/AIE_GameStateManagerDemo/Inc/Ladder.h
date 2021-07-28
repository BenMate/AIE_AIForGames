#pragma once

#include "GameObject.h"

class Ladder : public GameObject
{
public:

	Ladder();
	virtual ~Ladder();

	virtual void Update(float deltaTime);
	virtual void Draw();


protected:

private:
};