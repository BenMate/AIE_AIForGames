#include "MainCharacter.h"
#include "KeyBoardBehaviour.h"

#include "Assets.h"

#include "raylib.h"


MainCharacter::MainCharacter()
{
	m_KbBehaviour = new KeyBoardBehaviour();
	
	SetBehaviour(m_KbBehaviour);
}

MainCharacter::~MainCharacter()
{
	SetBehaviour(nullptr);

	delete m_KbBehaviour;
}

void MainCharacter::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void MainCharacter::Draw()
{
	DrawTexture(MyAssets::playerCharacter, m_position.x, m_position.y, WHITE);

	//DrawTexturePro()

	GameObject::Draw();

}

void MainCharacter::UpdatePlayerWallCollision()
{
	int tilesize = 8; // 8 so you can fit through small gaps
	auto playerPos = GetPosition();

	auto LeftColor = MyAssets::GetImagePixel(MyAssets::colourBGRaw, playerPos.x - tilesize, playerPos.y);
	auto rightColor = MyAssets::GetImagePixel(MyAssets::colourBGRaw, playerPos.x + tilesize, playerPos.y);
	auto TopColor = MyAssets::GetImagePixel(MyAssets::colourBGRaw, playerPos.x, playerPos.y - tilesize);
	auto BottomColor = MyAssets::GetImagePixel(MyAssets::colourBGRaw, playerPos.x, playerPos.y + tilesize);

	if (LeftColor == 0xFF000000)
	{
		ApplyForce({ GetMaxForce(), 0.0f });
		SetVelocity({ 0.0f, GetVelocity().y });
	}

	if (rightColor == 0xFF000000)
	{
		ApplyForce({ GetMaxForce(), 0.0f });
		SetVelocity({ 0.0f, GetVelocity().y });
	}

	if (TopColor == 0xFF000000)
	{
		ApplyForce({ GetMaxForce(), 0.0f });
		SetVelocity({ GetVelocity().x, 0.0f });
	}

	if (BottomColor == 0xFF000000) 
	{
		ApplyForce({ GetMaxForce(), 0.0f });
		SetVelocity({ GetVelocity().x, 0.0f });
	}
	//doesnt work
}