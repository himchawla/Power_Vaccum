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

player::player(int _player)
{
	m_vPlayers = 0;
	m_InputHandler = new inputManager(_player);
	transform.m_Mass = 5.0f;
	GetTexture()->loadFromFile("Assets/Players/Roomba.png");
	GetSprite()->setTexture(*GetTexture());
	GetSprite()->setScale(64.0f / GetTexture()->getSize().x, 64.0f / GetTexture()->getSize().y);
	GetSprite()->setOrigin(GetTexture()->getSize().x * 0.5f, GetTexture()->getSize().y * 0.5f);

	switch (_player)
	{
	case 0:
		GetSprite()->setColor(sf::Color::Red);
		break;
	case 1:
		GetSprite()->setColor(sf::Color::Cyan);
		break;
	case 2:
		GetSprite()->setColor(sf::Color::Green);
		break;
	case 3:
		GetSprite()->setColor(sf::Color::Yellow);
		break;
	default:
		break;
	}
}


player::~player()
{
	if (m_InputHandler != nullptr)
	{
		delete m_InputHandler;
		m_InputHandler = 0;
	}
}


/***********************
* Update: AddForce
* @author: Himanshu Chawla
* @parameter: direction
********************/
void player::AddForce(sf::Vector2f _dir)
{
	transform.m_Force = _dir;
}

/***********************
* Update: Updates Player Position.
* @author: Himanshu Chawla
* @parameter: Delta time.
********************/
void player::Update(float _dT)
{
	PlayerCollision();

	float accelMult = 400.0f;
	transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);
	transform.m_Accelaration += (transform.m_Force / transform.m_Mass) * _dT * 200.0f;
	transform.m_Force = sf::Vector2f(0.0f, 0.0f);



	if (Magnitude(transform.m_Accelaration) > 0.0f)
	{
		if (transform.m_Accelaration.x > 0.1f || transform.m_Accelaration.x < -0.1f)
		{
			transform.m_Accelaration.x -= transform.m_Friction.x * (abs(transform.m_Accelaration.x) / transform.m_Accelaration.x) * _dT * 500.0f;
		}
		else
			transform.m_Accelaration.x = 0.0f;

		if (transform.m_Accelaration.y > 0.1f || transform.m_Accelaration.y < -0.1f)
		{
			transform.m_Accelaration.y -= transform.m_Friction.y * (abs(transform.m_Accelaration.y) / transform.m_Accelaration.y) * _dT * 500.0f;
		}
		else
			transform.m_Accelaration.y = 0.0f;
	}


	float mag = sqrt(pow(transform.m_Accelaration.x, 2) + pow(transform.m_Accelaration.y, 2));
	if (mag > 800.0f)
	{
		transform.m_Accelaration = (transform.m_Accelaration / mag) * 800.0f;
	}

	transform.m_Velocity += transform.m_Accelaration;
	transform.m_Velocity += m_InputHandler->GetMovementVector() * 5.0f;

	mag = sqrt(pow(transform.m_Velocity.x, 2) + pow(transform.m_Velocity.y, 2));
	if (mag > 500.0f)
	{
		transform.m_Velocity = (transform.m_Velocity / mag) * 500.0f;
	}

	transform.m_Position += transform.m_Velocity * _dT;

	GetSprite()->setPosition(transform.m_Position);
}

void player::SetPlayerVector(std::vector<player*>* _player)
{
	m_vPlayers = _player;
}

void player::PlayerCollision()
{
	float selfSpeed = Magnitude(transform.m_Velocity);
	std::cout << selfSpeed << std::endl;
	for (auto i : *m_vPlayers)
	{
		if (i != this)
		{
			float MinDistance = GetTexture()->getSize().x * GetSprite()->getScale().x;

			sf::Vector2f DistanceCalc = i->transform.m_Position - transform.m_Position;
			float Distance = sqrt(pow(DistanceCalc.x, 2) + pow(DistanceCalc.y, 2));


			float collSpeed = Magnitude(i->transform.m_Velocity);
			if (Distance <= MinDistance)
			{
				DistanceCalc = DistanceCalc / Distance;

				i->AddForce(transform.m_Velocity * 0.4f + DistanceCalc * selfSpeed * 0.4f - i->transform.m_Velocity * 0.25f);
			}
		}
	}
}
