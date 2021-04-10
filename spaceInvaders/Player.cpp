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
#include <iostream>

Player::Player(int _player)
{
	m_InputHandler = new inputManager(_player);

	GetTexture()->loadFromFile("Assets/Players/P1.png");
	GetSprite()->setTexture(*GetTexture());
	GetSprite()->setOrigin(GetTexture()->getSize().x * 0.5f, GetTexture()->getSize().y * 0.5f);
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

	PlayerCollision();
	//transform.m_Velocity += transform.m_Accelaration * _dT;

	transform.m_Position += transform.m_Velocity * _dT;

	transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);
	GetSprite()->setPosition(transform.m_Position);
}

void Player::SetPlayerVector(std::vector<Player*>* _player)
{
	m_vPlayers = _player;
}

void Player::PlayerCollision()
{
	for (auto i : *m_vPlayers)
	{
		if(i != this)
		{
			float MinDistance = GetTexture()->getSize().x * GetSprite()->getScale().x;

			sf::Vector2f DistanceCalc = transform.m_Position - i->transform.m_Position;
			float Distance = sqrt(pow(DistanceCalc.x, 2) + pow(DistanceCalc.y, 2));
			std::cout << transform.m_Force.x << std::endl;
			if (Distance <= MinDistance)
			{	
				i->transform.m_Velocity = transform.m_Velocity;
				std::cout << "Bump\n";
				//yeet
			}
		}
	}
}
