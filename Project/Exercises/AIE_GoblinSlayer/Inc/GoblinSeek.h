#pragma once

#include "Behaviour.h"
#include "raymath.h"
#include <functional>
#include <list>
#include <vector>

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

	int GetClosestPoint(std::vector<Vector2> points, Vector2 target);
	void CalculateSeekPath(GameObject* obj);
	void SetGraph(Graph2D* graph);

	

protected:

	Vector2 m_target;
	float m_targetRadius = 2.0f;

	std::function<void()> m_onArriveFn;

	std::vector<Vector2> m_path;
	std::vector<Vector2>::iterator m_iter;
	
	Graph2D* m_graph = nullptr;
	BlackBoard* m_blackBoard = nullptr;
private:
};