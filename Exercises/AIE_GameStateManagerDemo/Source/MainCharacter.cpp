#include "MainCharacter.h"
#include "KeyBoardBehaviour.h"

#include "BlackBoard.h"

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

	UpdatePlayerWallCollision(deltaTime);


	m_blackBoard->SetPlayerPos(&m_position);
}

void MainCharacter::Draw()
{
	
	DrawCharacter();
	GameObject::Draw();
}

void MainCharacter::DrawCharacter()
{
	Rectangle PlayersourceRec = { 0.0f ,0.0f ,32.0f ,32.0f };
	Rectangle PlayerdestRec = { m_position.x, m_position.y, 32.0f ,32.0f };
	Vector2 Playerorigin = { 16,16 };

	DrawTexturePro(MyAssets::playerCharacter, PlayersourceRec, PlayerdestRec, Playerorigin, 0.0f, WHITE);
}


void MainCharacter::UpdatePlayerWallCollision(float deltaTime)
{
	int tilesize = 8;
	auto playerPos = GetPosition();

	auto LeftColor = MyAssets::GetImagePixel(MyAssets::colourBGRaw, playerPos.x - tilesize, playerPos.y);
	auto rightColor = MyAssets::GetImagePixel(MyAssets::colourBGRaw, playerPos.x + tilesize, playerPos.y);
	auto TopColor = MyAssets::GetImagePixel(MyAssets::colourBGRaw, playerPos.x, playerPos.y - tilesize);
	auto BottomColor = MyAssets::GetImagePixel(MyAssets::colourBGRaw, playerPos.x, playerPos.y + tilesize);

	if (LeftColor == 0xFF000000)
	{
		ApplyForce({ GetMaxForce(), 0.2f });
		SetVelocity({ 0.0f, GetVelocity().y });
	}

	if (rightColor == 0xFF000000)
	{
		ApplyForce({ -GetMaxForce(), 0.2f });
		SetVelocity({ 0.0f, GetVelocity().y });
	}

	if (TopColor == 0xFF000000)
	{
		ApplyForce({ 0.2f, GetMaxForce() });
		SetVelocity({ GetVelocity().x, 0.0f });
	}

	if (BottomColor == 0xFF000000) 
	{
		ApplyForce({ 0.2f, -GetMaxForce() });;
		SetVelocity({ GetVelocity().x, 0.0f });
	}
	
}