#pragma once

#include "raymath.h"

class Behaviour;

class GameObject 
{
public:

	GameObject();
	virtual ~GameObject();

	virtual void Update(float deltaTime);
	virtual void Draw();

	void ApplyForce(const Vector2& force);

	//Getters
	const Vector2& GetPosition() const;
	const Vector2& GetVelocity() const;
	const float& GetFriction() const;
	const float& GetMaxSpeed() const;
	const float& GetMaxForce() const;
	
	//Setters
	void SetPosition(const Vector2& pos);
	void SetVelocity(const Vector2& vel);
	void SetFriction(const float& friction);
	void SetMaxSpeed(const float& maxSpeed);
	void SetMaxForce(const float& maxForce);


	Behaviour* GetBehaviour();
	void SetBehaviour(Behaviour* behaviour);


protected:

	Vector2 m_position = { 0.0f , 0.0f };
	Vector2 m_velocity = { 0.0f , 0.0f };
	Vector2 m_acceleration = { 0.0f , 0.0f };
	float m_friction = 0.0f;
	float m_maxSpeed = 0.0f;
	float m_maxForce = 0.0f;

	Behaviour* m_behaviour = nullptr;
	

private:

};