#include "WonderBehaviour.h"
#include "GameObject.h"

#include <iostream>



WanderBehaviour::WanderBehaviour() : Behaviour()
{
	m_target = { 0,0 };
}

WanderBehaviour::~WanderBehaviour()
{

}

void WanderBehaviour::Begin(GameObject* obj)
{
	GenerateNewWanderTarget(obj);
}

void WanderBehaviour::Update(GameObject* obj, float deltaTime)
{
	float gap = 5;
	float DistanceToWanderPoint = Vector2Length(Vector2Subtract(m_wanderPoint, obj->GetPosition()));
	
	// Goblin reached target
	if (DistanceToWanderPoint < gap) 
	{ 	
		GenerateNewWanderTarget(obj);
	}
		Vector2 wanderTD = Vector2Scale(Vector2Normalize(Vector2Subtract(m_wanderPoint, obj->GetPosition())), obj->GetMaxForce());

		obj->ApplyForce(wanderTD);	
}

void WanderBehaviour::Draw(GameObject* obj)
{
	if (IsKeyDown(KEY_TAB))
	{
		DrawCircle(m_wanderPoint.x, m_wanderPoint.y, 10, GREEN);
	}
	
}

void WanderBehaviour::GenerateNewWanderTarget(GameObject* obj)
{
	m_wanderCenter = obj->GetPosition(); //get a pos for the wc
	auto angle = (rand() % 360) * PI / 180.0f;
	Vector2 displace = { sin(angle) * m_targetRadius, cos(angle) * m_targetRadius };
	m_wanderPoint = Vector2Add(m_wanderCenter, displace);
}

const Vector2& WanderBehaviour::GetTarget() const
{
	return m_target;
}
void WanderBehaviour::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& WanderBehaviour::GetTargetRadius() const
{
	return m_targetRadius;
}

void WanderBehaviour::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}

void WanderBehaviour::OnArrive(std::function<void()> callback)
{
	m_onArriveFn = callback;
}
