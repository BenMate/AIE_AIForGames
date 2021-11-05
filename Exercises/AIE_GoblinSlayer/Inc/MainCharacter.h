#pragma once

#include "GameObject.h"

class KeyBoardBehaviour;

class MainCharacter : public GameObject
{
public:

	MainCharacter();
	virtual ~MainCharacter();

	virtual void Update(float deltaTime);
	virtual void Draw();


	void DrawCharacter();
	void UpdatePlayerWallCollision(float deltaTime);


	float m_chestRadius = 30.0f;
protected:

	KeyBoardBehaviour* m_KbBehaviour;
	
private:
};