#include "Player.h"

Player::~Player()
{
}

void Player::Update(float _dT)
{
	transform.m_Velocity += m_InputHandler->GetMovementVector() * 5.0f;

	transform.m_Velocity += transform.m_Accelaration * _dT;


	//	transform.m_Force = sf::Vector2f(0.0f, 0.0f);


	transform.m_Position += transform.m_Velocity * _dT;

	transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);
	GetSprite()->setPosition(transform.m_Position);
}
