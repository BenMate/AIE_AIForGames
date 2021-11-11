#include "Goblin.h"
#include "GoblinSeek.h"
#include "WonderBehaviour.h"
#include "PatrolBehaviour.h"

#include "Graph2D.h"
#include "BlackBoard.h"

#include "raylib.h"
#include "Assets.h"

#include <vector>

Goblin::Goblin(Graph2D* graph, BlackBoard* blackboard) : GameObject()
{
	m_graph = graph;
	m_blackBoard = blackboard;

	m_goblinSeekBehaviour = new GoblinSeekBehaviour(m_graph, m_blackBoard);
	m_goblinSeekBehaviour->SetTargetRadius(50);

	m_wanderBehaviour = new WanderBehaviour();
	m_wanderBehaviour->SetTargetRadius(50);
	
	m_patrolBehaviour = new PatrolBehaviour(m_graph);
	m_patrolBehaviour->SetGraph(m_graph);
}

Goblin::~Goblin()
{
	SetBehaviour(nullptr);

	delete m_goblinSeekBehaviour;
	m_goblinSeekBehaviour = nullptr;

	delete m_wanderBehaviour;
	m_wanderBehaviour = nullptr;

	delete m_patrolBehaviour;
	m_patrolBehaviour = nullptr;
}

void Goblin::Update(float deltaTime)
{
	UpdateBehavior();

	UpdateAlphaColour(deltaTime);

	PlayerCaught();

	GameObject::Update(deltaTime);
}

void Goblin::Draw()
{
	

	GameObject::Draw();


	//the longer the player is in the radius of the goblin... the alpha goes up
	

	//convert int m_alpha to unsigned char
	unsigned char alpha; alpha = (unsigned char)m_alpha;
	DrawCircle(m_position.x, m_position.y, m_goblinRadius, { 230, 41, 55, alpha });
	
	//draws goblin
	Rectangle goblinsourceRec = { 0.0f ,0.0f ,19.0f ,24.0f };
	Rectangle goblindestRec = { m_position.x, m_position.y, 19.0f ,24.0f };
	Vector2   goblinorigin = { 9.5,12 };
	DrawTexturePro(MyAssets::goblinWand, goblinsourceRec, goblindestRec, goblinorigin, 0.0f, WHITE);		
}

Behaviour* Goblin::CalculateBehaviour()
{
	if (IsPlayerPositionKnown()) 
	{
		m_goblinSeekBehaviour->SetTarget(m_blackBoard->playersPos);  
		return m_goblinSeekBehaviour;
	}

	if (m_wanderer == true) //50% of goblins will be a wanderer the others will be patrollers
	{
		return m_wanderBehaviour;
	}

	return m_patrolBehaviour;
}


bool Goblin::IsPlayerPositionKnown()
{
	return m_blackBoard->positionKnown;	
}

void Goblin::UpdateBehavior() 
{
	auto currentBehaviour = GetBehaviour();
	auto desiredBehaviour = CalculateBehaviour();

	if (currentBehaviour != desiredBehaviour)
	{
		if (currentBehaviour != nullptr)
			currentBehaviour->End(this);

		SetBehaviour(desiredBehaviour);

		if (desiredBehaviour != nullptr)
			desiredBehaviour->Begin(this);
	}
}

void Goblin::UpdateAlphaColour(float deltaTime) 
{
	//distance of the player and goblin
	float distance = Vector2Length(Vector2Subtract(this->GetPosition(), m_blackBoard->playersPos));

	//resets the value if player isnt inside radius of goblin
	if (distance > 100)
	{
		m_alpha = 30;
	}

	if (distance < 100) 
	{
		m_alpha += deltaTime * 70;
	}		
}

bool Goblin::PlayerCaught() 
{
	if (m_alpha >= 255) 
	{
		std::cout << "Player was spotted" << std::endl;	

		return true;
	}
	return false;
}