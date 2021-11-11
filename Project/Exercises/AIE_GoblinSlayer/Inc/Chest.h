#pragma once

#include "GameObject.h"

class Chest : public GameObject
{
public:

	Chest();
	virtual ~Chest();

	virtual void Update(float deltaTime);
	virtual void Draw();

	void DrawChest();
	bool UpdateOpenChest();

	int GetScore();
	

	float m_chestRadius = 30.0f;
	
protected:

	bool OpenChest = false;

	int m_score = 0;

private:

};