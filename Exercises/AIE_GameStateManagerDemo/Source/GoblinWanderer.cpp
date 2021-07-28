#include "GoblinWanderer.h"
#include "SeekBehaviour.h"
#include "WonderBehaviour.h"

#include "raylib.h"
#include "Assets.h"

GoblinWanderer::GoblinWanderer()
{
	m_seekBehaviour = new SeekBehaviour();

	m_seekBehaviour->SetTargetRadius(50);

	m_seekBehaviour->OnArrive([this](){
		SetBehaviour(m_wanderBehaviour);
	});

	m_wanderBehaviour = new WanderBehaviour();

    //do wonder stuff

	SetBehaviour(m_wanderBehaviour);
}

GoblinWanderer::~GoblinWanderer()
{
	SetBehaviour(nullptr);

	delete m_seekBehaviour;
	delete m_wanderBehaviour;
}

void GoblinWanderer::Update(float deltaTime)
{
	
	//test the seek
	if (IsMouseButtonPressed(0))
	{
		m_seekBehaviour->SetTarget(GetMousePosition());
		SetBehaviour(m_seekBehaviour);
	}

	GameObject::Update(deltaTime);
}

void GoblinWanderer::Draw()
{
	Rectangle goblinsourceRec = { 0.0f ,0.0f ,19.0f ,24.0f };
	Rectangle goblindestRec = { m_position.x, m_position.y, 19.0f ,24.0f };
	Vector2 goblinorigin = { 9.5,12 };

	DrawTexturePro(MyAssets::goblinWand, goblinsourceRec, goblindestRec, goblinorigin, 0.0f, WHITE);

	GameObject::Draw();
}

