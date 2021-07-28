#include "WonderBehaviour.h"
#include "GameObject.h"


WanderBehaviour::WanderBehaviour() : Behaviour()
{
	m_target = { 0,0 };
}

WanderBehaviour::~WanderBehaviour()
{

}

void WanderBehaviour::Update(GameObject* obj, float deltaTime)
{
	//float Gap = 15;
	//float DistanceToWwanderPoint = Vector2Length(Vector2Subtract(m_wanderPoint, obj->GetPosition()));
	//
	//if (DistanceToWwanderPoint < Gap || Vector2Length(obj->GetVelocity()) == 0) //not moving or they reached target
	//{ 
	//	Vector2 newVelocity = { 1, 1 };

	//	if (Vector2Length(obj->GetVelocity()) == 1) obj->SetVelocity(newVelocity);

	//	WanderCentre = obj->GetPosition(); //get a pos for the wc
	//	auto angle = (rand() % 360) * PI / 180.0f;
	//	Vector2 displace = { sin(angle) * m_targetRadius, cos(angle) * m_targetRadius };
	//	Vector2 wp = Vector2Add(WanderCentre, displace);
	//	m_wanderCenter = obj->GetPosition();
	//	m_wanderPoint = wp;
	//}
	//Vector2 wanderTD = Vector2Scale(Vector2Normalize(Vector2Subtract(m_wanderPoint, obj->GetPosition())),
	//	obj->GetMaxForce());

	//	obj->ApplyForce(wanderTD);

	
}

void WanderBehaviour::Draw(GameObject* obj)
{
	


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