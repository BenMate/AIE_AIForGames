#pragma once

#include "Behaviour.h"
#include "raymath.h"
#include <functional>

class WanderBehaviour : public Behaviour
{
public:

	WanderBehaviour();

	virtual ~WanderBehaviour();

	virtual void Begin(GameObject* obj);

	virtual void Update(GameObject* obj, float deltaTime);
	virtual void Draw(GameObject* obj);

	const Vector2& GetTarget() const;
	void SetTarget(const Vector2& target);

	const float& GetTargetRadius() const;
	void SetTargetRadius(const float& radius);

	void OnArrive(std::function<void()>callback);

	void CalculateWanderPath();
	void ApplyWanderForce();

protected:

	void GenerateNewWanderTarget(GameObject* obj);

private:

	Vector2 m_target;
	Vector2 m_wanderCenter;
	Vector2 m_wanderPoint;

	float m_targetRadius = 30.0f;

	std::function<void()> m_onArriveFn;

private:
};
