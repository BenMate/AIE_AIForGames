#include "WonderBehaviour.h"
#include "GameObject.h"


WonderBehaviour::WonderBehaviour() : Behaviour()
{
	m_target = { 0,0 };
}

WonderBehaviour::~WonderBehaviour()
{

}

void WonderBehaviour::Update(GameObject* obj, float deltaTime)
{



}

void WonderBehaviour::Draw(GameObject* obj)
{
	


}

const Vector2& WonderBehaviour::GetTarget() const
{
	return m_target;
}
void WonderBehaviour::SetTarget(const Vector2& target)
{
	m_target = target;
}

const float& WonderBehaviour::GetTargetRadius() const
{
	return m_targetRadius;
}

void WonderBehaviour::SetTargetRadius(const float& radius)
{
	m_targetRadius = radius;
}

void WonderBehaviour::OnArrive(std::function<void()> callback)
{
	m_onArriveFn = callback;
}