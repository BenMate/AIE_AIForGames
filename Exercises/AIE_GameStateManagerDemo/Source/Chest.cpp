#include "Chest.h"
#include "Assets.h"
#include "raylib.h"


Chest::Chest()
{
	
}

Chest::~Chest()
{
	
}

void Chest::Update(float deltaTime)
{

	//float dist = Vector2Distance(m_gameState->GetPlayer()->GetPosition(), GetPosition());
	//float playerChestDistance = Vector2Distance(,GetPosition());


	GameObject::Update(deltaTime);
}

void Chest::Draw()
{
	Rectangle chestSourceRec = { 0.0f ,0.0f ,24.0f ,24.0f };
	Rectangle chestDestRec = { m_position.x, m_position.y, 24.0f ,24.0f };
	Vector2 chestOrigin = { 12,12 };

	DrawTexturePro(MyAssets::chestC, chestSourceRec, chestDestRec, chestOrigin, 0.0f, WHITE);

	GameObject::Draw();

}