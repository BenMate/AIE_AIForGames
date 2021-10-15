#pragma once

#include "Behaviour.h"
#include "raymath.h"
#include <functional>
#include <list>

class Graph2D;
class BlackBoard;

class GoblinSeekBehaviour : public Behaviour
{
public:

	GoblinSeekBehaviour(Graph2D* graph, BlackBoard* blackboard);

	virtual ~GoblinSeekBehaviour();

	virtual void Update(GameObject* obj, float deltaTime);
	virtual void Draw(GameObject* obj);

	void ApplySeekForce(Vector2 target, GameObject* obj);

	const Vector2& GetTarget() const;
	void SetTarget(const Vector2& target);

	const float& GetTargetRadius() const;
	void SetTargetRadius(const float& radius);

	void OnArrive(std::function<void()>callback);


	void CalculateSeekPath(GameObject* obj);
	void SetGraph(Graph2D* graph);

protected:

	Vector2 m_target;
	float m_targetRadius = 2.0f;

	std::function<void()> m_onArriveFn;

	std::list<Vector2> m_path;
	std::list<Vector2>::iterator m_iter;
	std::list<Vector2> m_patrolPath;

	Graph2D* m_graph = nullptr;
	BlackBoard* m_blackBoard = nullptr;
private:
};