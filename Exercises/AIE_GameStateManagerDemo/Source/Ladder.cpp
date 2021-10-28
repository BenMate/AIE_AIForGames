#include "Ladder.h"
#include "Assets.h"

#include "raylib.h"

#include "BlackBoard.h"

#include <iostream>

LadderEntity::LadderEntity()
{

}

LadderEntity::~LadderEntity()
{

}

void LadderEntity::Update(float deltaTime)
{

	GameObject::Update(deltaTime);
}

void LadderEntity::Draw()
{	
	DrawLadder();
	GameObject::Draw();
}

void LadderEntity::DrawLadder()
{
	Rectangle ladderSourceRec = { 0.0f ,0.0f ,17.0f ,28.0f };
	Rectangle ladderDestRec = { m_position.x, m_position.y, 17.0f ,28.0f };
	Vector2 ladderOrigin = { 8.5,14 };

	DrawTexturePro(MyAssets::Ladder, ladderSourceRec, ladderDestRec, ladderOrigin, 0.0f, WHITE);
}

bool LadderEntity::IsNearLadder()
{
	Vector2* playerPos = &m_blackBoard->playersPos;

	if (playerPos == nullptr)
		return false;
	
	float playerladderDistance = Vector2Distance(*playerPos, GetPosition()); 

	if (playerladderDistance < m_LadderRadius)	
		return true;
	

	return false;
}