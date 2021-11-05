#include "GameObject.h"
#include "Behaviour.h"

#include "BlackBoard.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Update(float deltaTime)
{
	if (m_behaviour != nullptr)
		m_behaviour->Update(this, deltaTime);

	ApplyForce(Vector2Scale(Vector2Negate(m_velocity), m_friction));

	m_velocity = Vector2Add(m_velocity, Vector2Scale(m_acceleration, deltaTime));
	m_position = Vector2Add(m_position, Vector2Scale(m_velocity, deltaTime));
}

void GameObject::Draw()
{
	if (m_behaviour != nullptr)
		m_behaviour->Draw(this);

	Vector2 heading = Vector2Add(m_position, m_velocity);
	//where the player is heading
	//DrawLine(m_position.x, m_position.y, heading.x, heading.y, BLACK);
	//where the player is currently being told to go
	//DrawLine(m_position.x, m_position.y, m_position.x + m_acceleration.x, m_position.y + m_acceleration.y, RED);

	m_acceleration = { 0,0 };
}


void GameObject::ApplyForce(const Vector2& force)
{
	m_acceleration = Vector2Add(m_acceleration, force);
}

//Getters
BlackBoard* GameObject::GetBlackBoard()
{
	return m_blackBoard;
}

const Vector2& GameObject::GetPosition() const
{
	return m_position;
}

const Vector2& GameObject::GetVelocity() const
{
	return m_velocity;
}

const float& GameObject::GetFriction() const
{
	return m_friction;
}

Behaviour* GameObject::GetBehaviour()
{
	return m_behaviour;
}

const float& GameObject::GetMaxSpeed() const
{
	return m_maxSpeed;
}

const float& GameObject::GetMaxForce() const
{
	return m_maxForce;
}

//Setters
void GameObject::SetPosition(const Vector2& pos)
{
	m_position = pos;
}

void GameObject::SetVelocity(const Vector2& vel)
{
	m_velocity = vel;
}

void GameObject::SetFriction(const float& friction)
{
	m_friction = friction;
}

void GameObject::SetMaxSpeed(const float& maxSpeed)
{
	m_maxSpeed = maxSpeed;
}

void GameObject::SetMaxForce(const float& maxForce) {
	m_maxForce = maxForce;
}

void GameObject::SetBehaviour(Behaviour* behaviour)
{
	m_behaviour = behaviour;
}

void GameObject::SetBlackBoard(BlackBoard* blackboard)
{
	m_blackBoard = blackboard;
}

