#include "Ladder.h"
#include "Assets.h"
#include "raylib.h"


Ladder::Ladder()
{

}

Ladder::~Ladder()
{

}

void Ladder::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	//UpdatePlayerWallCollision();
}

void Ladder::Draw()
{
	Rectangle chestSourceRec = { 0.0f ,0.0f ,24.0f ,24.0f };
	Rectangle chestDestRec = { m_position.x, m_position.y, 24.0f ,24.0f };
	Vector2 chestOrigin = { 12,12 };

	DrawTexturePro(MyAssets::chestC, chestSourceRec, chestDestRec, chestOrigin, 0.0f, WHITE);

	//if (playerwalks near) draw ladder

	GameObject::Draw();

}