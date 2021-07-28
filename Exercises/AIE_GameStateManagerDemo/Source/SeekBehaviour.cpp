#include "SeekBehaviour.h"
#include "GameObject.h"


SeekBehaviour::SeekBehaviour() : Behaviour()
{
	m_target = { 0,0 };
}

SeekBehaviour::~SeekBehaviour()
{

}

void SeekBehaviour::Update(GameObject* obj, float deltaTime)
{

	float distToTarget = Vector2Distance(obj->GetPosition(), m_target);

	if (distToTarget < m_targetRadius) {
		if (m_onArriveFn) {
			m_onArriveFn();
		}
	}

	Vector2 heading = Vector2Add(obj->GetPosition(), obj->GetVelocity());
	float headingLength = Vector2Length(heading);

	Vector2 dirToTaget = Vector2Normalize(Vector2Subtract(m_target, obj->GetPosition()));
	Vector2 vecToTarget = Vector2Scale(dirToTaget, headingLength);

	Vector2 targetForcepos = Vector2Add(vecToTarget, obj->GetPosition());
	Vector2 forceDir = Vector2Subtract(targetForcepos, heading);

	obj->ApplyForce(forceDir);
}

void SeekBehaviour::Draw(GameObject* obj)
{
	DrawCircle(m_target.x, m_target.y, m_targetRadius, LIGHTGRAY);
	DrawCircle(m_target.x, m_target.y, 5, GRAY);
}

const Vector2& SeekBehaviour::GetTarget() const
{
	return m_target;
}
void SeekBehaviour::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& SeekBehaviour::GetTargetRadius() const
{
	return m_targetRadius;
}

void SeekBehaviour::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}

void SeekBehaviour::OnArrive(std::function<void()> callback)
{
	m_onArriveFn = callback;
}