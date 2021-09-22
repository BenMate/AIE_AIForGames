#pragma once

#include "GameObject.h"
#include <list>



class GoblinSeekBehaviour;
class WanderBehaviour;
class PatrolBehaviour;

class Graph2D;


class Goblin : public GameObject
{
public:

	Goblin(Graph2D* graph, BlackBoard* blackboard);
	virtual ~Goblin();

	virtual void Update(float deltaTime);
	virtual void Draw();

	bool IsPlayerPositionKnown();


	Behaviour* CalculateBehaviour();

	float m_goblinRadius = 90.0f;

protected:

	bool m_IsPlayerPositionKnown = false;
	bool m_wanderer = rand() % 2 == 0;

	GoblinSeekBehaviour* m_goblinSeekBehaviour;
	WanderBehaviour* m_wanderBehaviour;
	PatrolBehaviour* m_patrolBehaviour;

	std::list<Vector2> m_path;
	std::list<Vector2>::iterator m_iter;
	std::list<Vector2> m_patrolPath;

	Graph2D* m_graph = nullptr;

private:
};