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

player::player(int _player, b2World& _world): gameObject(_world)
{
	m_vPlayers = 0;
	m_InputHandler = new inputManager(_player);
	transform.m_Mass = 1.0f;
	SetSpriteFromFile("Assets/Players/Roomba.png");
	m_ability = battery::ability::none;
	m_abilityTimer = 0.0f;

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
	transform.m_Force += _dir;
}

/***********************
* Update: Updates Player Position.
* @author: Himanshu Chawla
* @parameter: Delta time.
********************/
void player::Update(float _dT)
{

	//Check Collisions
	/*PlayerCollision();
	BatteryCollision();
	BatteryImplementation(_dT);*/
	
	GetBody()->SetLinearVelocity(b2Vec2((m_InputHandler->GetMovementVector() * 50.0f).x, (m_InputHandler->GetMovementVector() * 5.0f).y));
	std::cout << GetBody()->GetPosition().x<<"\n";
	//Update sprite position
	GetSprite()->setPosition(sf::Vector2f(GetBody()->GetPosition().x, GetBody()->GetPosition().y));
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

void player::SetBatteryVector(std::vector<battery*>* _battery)
{
	m_vBatteries = _battery;
}

/***********************
* Update: Checks Player Collision
* @author: Neel Kolhe
********************/
void player::PlayerCollision()
{
	float selfSpeed = Magnitude(transform.m_Velocity);		//sets the speed of the player
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
				if(m_ability==battery::ability::turtle)
					i->AddForce(transform.m_Velocity/Magnitude(transform.m_Velocity) * 10000.0f + DistanceCalc * selfSpeed * 2000.0f);		//Adds the bounce back effect on the two units
				//else if(m_ability == battery::ability::magnetic)
					//i->AddForce(transform.m_Velocity / Magnitude(transform.m_Velocity) * 10000.0f + DistanceCalc * selfSpeed * 2000.0f);		//Adds the bounce back effect on the two units
				else
					i->AddForce(transform.m_Velocity * 0.8f  + DistanceCalc * selfSpeed * 0.8f);		//Adds the bounce back effect on the two units

			
			}
			//std::cout << i->transform.m_Position.x << "\n";

		}
	}
}



void player::BatteryCollision()
{
	float selfSpeed = Magnitude(transform.m_Velocity);
	std::vector<battery*>::iterator it = m_vBatteries->begin();
	while (it != m_vBatteries->end())
	{
		float MinDistance = GetTexture()->getSize().x * GetSprite()->getScale().x;

		sf::Vector2f DistanceCalc = (*it)->transform.m_Position - transform.m_Position;
		float Distance = sqrt(pow(DistanceCalc.x, 2) + pow(DistanceCalc.y, 2));
		

		float collSpeed = Magnitude((*it)->transform.m_Velocity);
		if (Distance <= MinDistance)
		{
			m_abilityTimer = (*it)->GetAbilityTimer();
			m_ability = (*it)->m_ability;
			delete (*it);
			m_vBatteries->erase(it);
			break;
		}

		it++;
	}
	
}

void player::BatteryImplementation(float _dt)
{
	switch (m_ability)
	{
	case battery::none:
		break;
	case battery::turtle:
	{
		transform.m_Mass *= 10.0f;
	}
		break;
	case battery::magnetic:
	{
		for (auto it : *m_vPlayers)
		{
			if (it != this)
			{
				float mag = Magnitude(transform.m_Position - it->transform.m_Position);
				it->AddForce((transform.m_Position - it->transform.m_Position)/mag * 6.2f);
				
			}
		}
	}
		break;
	case battery::leaking:
		break;
	default:
		break;
	}
}
