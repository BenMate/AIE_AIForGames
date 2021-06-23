#include "Player.h"
#include "KeyBoardBehaviour.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"

Player::Player()
{
	m_KbBehaviour = new KeyBoardBehaviour();
	m_seekBehaviour = new SeekBehaviour();
	m_seekBehaviour->SetTargetRadius(50);
	m_seekBehaviour->OnArrive([this](){
			SetBehaviour(m_KbBehaviour);
	});

	m_FleeBehaviour = new FleeBehaviour();
	m_FleeBehaviour->SetTargetRadius(200);
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
	if (IsMouseButtonPressed(0)) //left click
	{
		m_seekBehaviour->SetTarget( GetMousePosition() );
		SetBehaviour(m_seekBehaviour);
	}

	if (IsMouseButtonPressed(1)) // right click
	{
		m_FleeBehaviour->SetTarget(GetMousePosition());
		SetBehaviour(m_FleeBehaviour);
	}

	//if (
	//m_wonderBehaviour->SetTarget(SomethingRandomonWindow));
	//SetBehaviour(m_wonderBehaviour);

	//else keyboayd

	GameObject::Update(deltaTime);
}

void Player::Draw()
{

	GameObject::Draw();
}