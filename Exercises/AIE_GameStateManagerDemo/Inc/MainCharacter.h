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

	void UpdatePlayerWallCollision();

protected:


	KeyBoardBehaviour* m_KbBehaviour;


private:
};