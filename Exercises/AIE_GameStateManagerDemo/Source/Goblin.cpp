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

	//m_wanderBehaviour = new WanderBehaviour();
	
	//m_patrolBehaviour = new PatrolBehaviour();
	//m_patrolBehaviour->SetGraph(m_graph);
	//m_patrolBehaviour->CalculatePatrolPath(this);

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
	auto currentBehaviour = GetBehaviour();
	auto desiredBehaviour = CalculateBehaviour();

	if (currentBehaviour != desiredBehaviour)
	{
		SetBehaviour(desiredBehaviour);		
	}

	GameObject::Update(deltaTime);
}

void Goblin::Draw()
{
	

	Rectangle goblinsourceRec = { 0.0f ,0.0f ,19.0f ,24.0f };
	Rectangle goblindestRec = { m_position.x, m_position.y, 19.0f ,24.0f };
	Vector2   goblinorigin = { 9.5,12 };

	GameObject::Draw();

	DrawCircle(m_position.x, m_position.y, m_goblinRadius, RED);

	DrawTexturePro(MyAssets::goblinWand, goblinsourceRec, goblindestRec, goblinorigin, 0.0f, WHITE);

	if (IsKeyDown(KEY_TAB)) 
	{
		for (auto& c : m_patrolPath)
		{
			DrawCircle(c.x,c.y,10,RED);
		}
	}
	
}

Behaviour* Goblin::CalculateBehaviour()
{

	// temp:
	return m_goblinSeekBehaviour;

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


