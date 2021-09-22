#include "Chest.h"
#include "Assets.h"

#include "raylib.h"

#include "BlackBoard.h"

#include <time.h>
#include <iostream>

Chest::Chest()
{

}

Chest::~Chest()
{

}

void Chest::Update(float deltaTime)
{
	UpdateOpenChest();
	GameObject::Update(deltaTime);
}

void Chest::Draw()
{
	GameObject::Draw();
	DrawChest();
	
}

bool Chest::UpdateOpenChest() 
{
	Vector2* playerPos = &m_blackBoard->playersPos;
	

	//checks if playerpos isnt updated;
	if (playerPos == nullptr)
	{
		return false;
	}

	float playerChestDistance = Vector2Distance(*playerPos, GetPosition()); //playersPos, ChestPos

	if (playerChestDistance < m_chestRadius) //if player is inside chests radius
	{
		if (!OpenChest)
		{
			srand(time(nullptr));
			m_blackBoard->score += rand() % 500 + 100;
			OpenChest = true;
		}
		std::cout << m_blackBoard->score << std::endl;
	}
	return OpenChest;
}

void Chest::DrawChest()
{
	Rectangle chestSourceRec = { 0.0f ,0.0f ,24.0f ,24.0f };
	Rectangle chestDestRec = { m_position.x, m_position.y, 24.0f ,24.0f };
	Vector2 chestOrigin = { 12,12 };

	if (IsKeyDown(KEY_TAB))
	{
		DrawCircle(m_position.x, m_position.y, m_chestRadius, BLUE);
	}

	Texture2D chest = OpenChest ? MyAssets::chestO : MyAssets::chestC; // chest gets updated when openchest = true;
	DrawTexturePro(chest, chestSourceRec, chestDestRec, chestOrigin, 0.0f, WHITE);
}
