#pragma once

#include "Behaviour.h"
#include "raymath.h"
#include <functional>
#include <list>

class Graph2D;

class PatrolBehaviour : public Behaviour
{
public:

	PatrolBehaviour();

	virtual ~PatrolBehaviour();

	virtual void Update(GameObject* obj, float deltaTime);
	virtual void Draw(GameObject* obj);

	const Vector2& GetTarget() const;
	void SetTarget(const Vector2& target);

	const float& GetTargetRadius() const;
	void SetTargetRadius(const float& radius);

	void OnArrive(std::function<void()>callback);

	void CalculatePatrolPath(GameObject* obj);
	void SetGraph(Graph2D* graph);

protected:

	Vector2 m_target;
	Vector2 WanderCentre;
	Vector2 m_wanderCenter;
	Vector2 m_wanderPoint;

	float m_targetRadius = 1.0f;

	std::function<void()> m_onArriveFn;

	std::list<Vector2> m_path;
	std::list<Vector2>::iterator m_iter;
	std::list<Vector2> m_patrolPath;

	Graph2D* m_graph = nullptr;

private:
};