// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   Player.h
//  Description :   Player class inherits from the gameObject class
//  Author      :   Himanshu Chawla
//  Mail        :   himanshu.chawla@mds.ac.nz
// 
 // Library Includes 

//This include
#include "Player.h"

Player::Player(int _player)
{
	m_InputHandler = new inputManager(_player);

	GetTexture()->loadFromFile("Assets/Players/P1.png");
	GetSprite()->setTexture(*GetTexture());
}


Player::~Player()
{
	if (m_InputHandler != nullptr)
	{
		delete m_InputHandler;
		m_InputHandler = 0;
	}
}

void Player::addForce(sf::Vector2f dir)
{
	transform.m_Force = dir;
}



/***********************
* Update: Updates Player Position.
* @author: Himanshu Chawla
* @parameter: Delta time.
********************/
void Player::Update(float _dT)
{


	transform.m_Accelaration += transform.m_Force / transform.m_Mass;
	transform.m_Force = sf::Vector2f(0.0f, 0.0f);

	transform.m_Velocity += transform.m_Accelaration;

	if (Magnitude(transform.m_Accelaration) > 0.0f)
	{
		if (transform.m_Accelaration.x > 0.1f || transform.m_Accelaration.x < -0.1f)
		{
			transform.m_Accelaration.x -= transform.m_Friction.x * (abs(transform.m_Accelaration.x) / transform.m_Accelaration.x);
		}
		else
			transform.m_Accelaration.x = 0.0f;

		if (transform.m_Accelaration.y > 0.1f || transform.m_Accelaration.y < -0.1f)
		{
			transform.m_Accelaration.y -= transform.m_Friction.y * (abs(transform.m_Accelaration.y) / transform.m_Accelaration.y);
		}
		else
		transform.m_Accelaration.y = 0.0f;
	}

	transform.m_Velocity += m_InputHandler->GetMovementVector() * 5.0f;

	//transform.m_Velocity += transform.m_Accelaration * _dT;

	transform.m_Position += transform.m_Velocity * _dT;

	transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);
	GetSprite()->setPosition(transform.m_Position);
}
