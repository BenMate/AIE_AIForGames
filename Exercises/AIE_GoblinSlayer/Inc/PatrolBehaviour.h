#pragma once

#include "Behaviour.h"
#include "raymath.h"
#include <functional>
#include <list>
#include <vector>

class Graph2D;

class PatrolBehaviour : public Behaviour
{
public:

	PatrolBehaviour(Graph2D* graph);

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
	int GetClosestPoint(std::vector<Vector2> points, Vector2 target);

	void ApplyPatrolForce(Vector2 target, GameObject* obj);

protected:

	Vector2 m_target;
	float m_targetRadius = 2.0f;

	int m_patrolPathDir = 1;

	std::function<void()> m_onArriveFn;

	std::vector<Vector2>::iterator m_iter;
	std::vector<Vector2> m_patrolPath;

	Graph2D* m_graph = nullptr;
	

private:
};