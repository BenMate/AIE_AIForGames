#pragma once

#include "GameObject.h"




class Chest : public GameObject
{
public:

	Chest();
	virtual ~Chest();

	virtual void Update(float deltaTime);
	virtual void Draw();


	//have a radius
	//draw a asset over the top or override ? asset1 : asset2....maybe

	float m_chestRadius = 100.0f;

protected:


private:
};