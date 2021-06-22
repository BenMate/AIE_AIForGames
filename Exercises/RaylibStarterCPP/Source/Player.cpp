#include "Player.h"
#include "KeyBoardBehaviour.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"

Player::Player()
{
	m_KbBehaviour = new KeyBoardBehaviour();
	m_seekBehaviour = new SeekBehaviour();
	m_seekBehaviour->SetTargetRadius(10);
	m_seekBehaviour->OnArrive([this](){
			SetBehaviour(m_KbBehaviour);
	});

	m_FleeBehaviour->SetTargetRadius(20);
	m_FleeBehaviour->OnArrive([this]() {
		SetBehaviour(m_KbBehaviour);
		});

	SetBehaviour(m_KbBehaviour);
}
Player::~Player()
{
	SetBehaviour(nullptr);

	delete m_FleeBehaviour;
	delete m_seekBehaviour;
	delete m_KbBehaviour;
}


void Player::Update(float deltaTime)
{
	if (IsMouseButtonPressed(0))
	{
		m_seekBehaviour->SetTarget( GetMousePosition() );
		SetBehaviour(m_seekBehaviour);
	}

	if (IsMouseButtonPressed(1))
	{
		m_FleeBehaviour->SetTarget(GetMousePosition());
		SetBehaviour(m_FleeBehaviour);
	}

	GameObject::Update(deltaTime);
}

void Player::Draw()
{

	GameObject::Draw();
}