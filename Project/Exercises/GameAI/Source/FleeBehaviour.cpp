#include "FleeBehaviour.h"
#include "GameObject.h"

FleeBehaviour::FleeBehaviour()
{
	m_target = { 0,0 };
}

FleeBehaviour::~FleeBehaviour()
{

}

void FleeBehaviour::Update(GameObject* obj, float deltaTime)
{

	float distToTarget = Vector2Distance(obj->GetPosition(), m_target);

	if (distToTarget > m_targetRadius) {
		if (m_onArriveFn) {
			m_onArriveFn();
		}
	}

	Vector2 heading = Vector2Add(obj->GetPosition(), obj->GetVelocity());
	float headingLength = Vector2Length(heading);

	Vector2 dirToTaget = Vector2Normalize(Vector2Subtract(m_target, obj->GetPosition()));
	Vector2 vecToTarget = Vector2Scale(dirToTaget, headingLength);

	Vector2 targetForcepos = Vector2Add(vecToTarget, obj->GetPosition());
	Vector2 forceDir = Vector2Scale(Vector2Subtract(targetForcepos, heading), -1); 


	obj->ApplyForce(forceDir);
}

void FleeBehaviour::Draw(GameObject* obj)
{
	DrawCircle(m_target.x, m_target.y, m_targetRadius, LIGHTGRAY);
	DrawCircle(m_target.x, m_target.y, 5, GRAY);
}

const Vector2& FleeBehaviour::GetTarget() const
{
	return m_target;
}
void FleeBehaviour::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& FleeBehaviour::GetTargetRadius() const
{
	return m_targetRadius;
}

void FleeBehaviour::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}

void FleeBehaviour::OnArrive(std::function<void()> callback)
{
	m_onArriveFn = callback;
}