#include "GoblinWanderer.h"
#include "SeekBehaviour.h"
#include "WonderBehaviour.h"

GoblinWanderer::GoblinWanderer()
{
	m_wanderBehaviour = new WanderBehaviour();
	m_seekBehaviour = new SeekBehaviour();

	m_seekBehaviour->SetTargetRadius(50);
	m_seekBehaviour->OnArrive([this]() {
		SetBehaviour(m_wanderBehaviour);
		});

	

	

	SetBehaviour(m_wanderBehaviour);
}

GoblinWanderer::~GoblinWanderer()
{
	SetBehaviour(nullptr);

	
	delete m_seekBehaviour;
	
}

void GoblinWanderer::Update(float deltaTime)
{
	



	GameObject::Update(deltaTime);
}

void GoblinWanderer::Draw()
{
	//draw asset   goblin
	GameObject::Draw();
}