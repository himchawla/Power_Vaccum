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

	// Load texture
	GetTexture()->loadFromFile("Assets/Players/Roomba.png");

	// Configure sprite
	GetSprite()->setTexture(*GetTexture());
	GetSprite()->setScale(64.0f / GetTexture()->getSize().x, 64.0f / GetTexture()->getSize().y);
	GetSprite()->setOrigin(GetTexture()->getSize().x * 0.5f, GetTexture()->getSize().y * 0.5f);

	// Set sprite colour
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

	//Check Collisions
	PlayerCollision();

	//Reset Velocity
	transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);
	
	//Calculate Accekaration from force
	transform.m_Acceleration += (transform.m_Force / transform.m_Mass) * _dT * 200.0f;
	
	//Reset Force
	transform.m_Force = sf::Vector2f(0.0f, 0.0f);


	//Retardation
	if (Magnitude(transform.m_Acceleration) > 0.0f)
	{
		if (transform.m_Acceleration.x > 0.1f || transform.m_Acceleration.x < -0.1f)
		{
			transform.m_Acceleration.x -= transform.m_Friction.x * (abs(transform.m_Acceleration.x) / transform.m_Acceleration.x) * _dT * 500.0f;
		}
		else
			transform.m_Acceleration.x = 0.0f;

		if (transform.m_Acceleration.y > 0.1f || transform.m_Acceleration.y < -0.1f)
		{
			transform.m_Acceleration.y -= transform.m_Friction.y * (abs(transform.m_Acceleration.y) / transform.m_Acceleration.y) * _dT * 500.0f;
		}
		else
			transform.m_Acceleration.y = 0.0f;
	}

	//Clamp Acceleration
	float mag = sqrt(pow(transform.m_Acceleration.x, 2) + pow(transform.m_Acceleration.y, 2));
	if (mag > 800.0f)
	{
		transform.m_Acceleration = (transform.m_Acceleration / mag) * 800.0f;
	}

	transform.m_Velocity += transform.m_Acceleration;
	transform.m_Velocity += m_InputHandler->GetMovementVector() * 5.0f;

	//Clamp Velocity
	mag = sqrt(pow(transform.m_Velocity.x, 2) + pow(transform.m_Velocity.y, 2));
	if (mag > 500.0f)
	{
		transform.m_Velocity = (transform.m_Velocity / mag) * 500.0f;
	}

	//Update Position from velocity
	transform.m_Position += transform.m_Velocity * _dT;

	//Update sprite position
	GetSprite()->setPosition(transform.m_Position);
}

/***********************
* Update: creates a Vector of all the players
* @author: Neel Kolhe
* parameters: Vector
********************/
void player::SetPlayerVector(std::vector<player*>* _player)
{
	m_vPlayers = _player;			//pushes the players onto a vector for checking the player collision
}

/***********************
* Update: Checks Player Collision
* @author: Neel Kolhe
********************/
void player::PlayerCollision()
{
	float selfSpeed = Magnitude(transform.m_Velocity);		//sets the speed of the player
	std::cout << selfSpeed << std::endl;					//writes the speed in the console
	for (auto i : *m_vPlayers)								//logs the opposing player
	{
		if (i != this)										//checks if the player is not the opposing
		{
			float MinDistance = GetTexture()->getSize().x * GetSprite()->getScale().x;		//calculates the minimum distance needed for collision between the two units

			sf::Vector2f DistanceCalc = i->transform.m_Position - transform.m_Position;		//calculates the distance between the two positions
			float Distance = sqrt(pow(DistanceCalc.x, 2) + pow(DistanceCalc.y, 2));			//gets the magnitude of the two positions


			float collSpeed = Magnitude(i->transform.m_Velocity);							//makes a float for the collspeed
			if (Distance <= MinDistance)					//if the two objects are colliding
			{
				DistanceCalc = DistanceCalc / Distance;		//gets the distance between the two units

				i->AddForce(transform.m_Velocity * 0.8f + DistanceCalc * selfSpeed * 0.8f - i->transform.m_Velocity * 0.5f);		//Adds the bounce back effect on the two units
			}
		}
	}
}
