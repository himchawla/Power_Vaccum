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


/***********************
* Normalize: Checks Battery Collision
* @author: Himanshu Chawla
* Parameter: Vector
* Return: Normalized Vector
********************/
sf::Vector2f Normalize(sf::Vector2f _v)
{
	float mag = sqrt(_v.x * _v.x + _v.y * _v.y);
	if (abs(mag) < 0.001f)	return sf::Vector2f(0.0f, 0.0f);

	_v /= mag;
	return _v;
}


player::player(int _player)
{
	m_DeathTimer = 0;
	m_vPlayers = 0;
	m_InputHandler = new inputManager(_player);
	transform.m_Mass = 1.0f;
	SetSpriteFromFile("Assets/Players/Roomba.png");
	m_ability = battery::eAbility::none;
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

	// Leaking battery variables
	m_bExphit = false;
	m_bWillDie = false;
	m_fDeathTimer = 0.0f;
	m_fDeathDelay = 2.0f;

	m_circleIndicator = sf::CircleShape(m_fExpRange);
	m_circleIndicator.setOrigin(sf::Vector2f(m_fExpRange, m_fExpRange));
	m_circleIndicator.setFillColor(sf::Color(200, 170, 130, 160));
	m_circleIndicator.setOutlineColor(sf::Color(255, 255, 255, 160));
	m_circleIndicator.setOutlineThickness(5.0f);
}


/***********************
* death: Kills a current player
* @author: Himanshu Chawla
* @parameter: N/A
********************/
void player::death()
{
	std::vector<player*>::iterator it = m_vPlayers->begin();
	while (it != m_vPlayers->end())
	{
		if (*it == this)
		{
  			m_vPlayers->erase(it);
			delete this;
			break;
		}
		it++;
	}
}

player::~player()
{
	if (m_InputHandler != nullptr)
	{
		delete m_InputHandler;
		m_InputHandler = 0;
	}
	if (m_DeathTimer != nullptr)
	{
		delete m_DeathTimer;
		m_DeathTimer = 0;
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
* AddPowerForce: AddForce
* @author: Himanshu Chawla
* @parameter: direction
********************/
void player::AddPowerForrce(sf::Vector2f dir)
{
	m_powerForce += dir;
}

/***********************
* Update: Updates Player Position.
* @author: Himanshu Chawla
* @parameter: Delta time.
********************/
void player::Update(float _dT)
{
	m_delay -= _dT;
	m_disableTimer -= _dT;
	if (Magnitude(m_externVel) < 0.01f)
	{
		m_disableControl = false;
	}

	//Check Collisions
	if (!m_bWillDie)
	{
		PlayerCollision();
		if(m_vBatteries!=nullptr)
			BatteryCollision();
	}
	BatteryImplementation(_dT);

	if (m_InputHandler->GetControllerButton(7) && m_delay < 0.0f)
	{
		m_ready = !m_ready;
		std::cout << "Player is " << m_ready;
		m_delay = 1.0f;
	}

	//for (int i = 0; i < 9; i++)
	//{
	//	if (m_InputHandler->GetControllerButton(i))
	//		exit(i);
	//}

	//Reset Velocity
	transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);

	#pragma region CollisionPhysics


	//Calculate Accekaration from force for Collision
	transform.m_Acceleration = (transform.m_Force / transform.m_Mass) * _dT * 200.0f;
	
	m_externVel += transform.m_Acceleration * 200.0f;

	//Reset Force
	transform.m_Force = sf::Vector2f(0.0f, 0.0f);
	transform.m_Acceleration = sf::Vector2f(0.0f, 0.0f);

	#pragma endregion
	
	#pragma region PowerupPhysics

	//Calculate Accekaration from force for PoweUps
	transform.m_Acceleration = (m_powerForce / transform.m_Mass) * _dT * 200.0f;

	m_forceVel += transform.m_Acceleration * 200.0f;

	transform.m_Acceleration = sf::Vector2f(0.0f, 0.0f);
	m_powerForce = sf::Vector2f(0.0f, 0.0f);
	#pragma endregion


	if (m_bExphit) // If player has been hit with explosion.
	{
		transform.m_Velocity = m_externVel;
		transform.m_Position += transform.m_Velocity * _dT;
		GetSprite()->setPosition(transform.m_Position);
		return; // Return before applying retardation and clamping.
	}

	//Retardation
	if (Magnitude(m_externVel) > 0.0f)
	{
		if (m_externVel.x > 10.0f || m_externVel.x < -10.0f)
		{
			m_externVel.x -= transform.m_Friction.x * (abs(m_externVel.x) / m_externVel.x) * _dT * 100.0f;
		}
		else
			m_externVel.x = 0.0f;

		if (m_externVel.y > 10.0f || m_externVel.y < -10.0f)
		{
			m_externVel.y -= transform.m_Friction.y * (abs(m_externVel.y) / m_externVel.y) * _dT * 100.0f;
		}
		else
			m_externVel.y = 0.0f;
	}

	if (Magnitude(m_forceVel) > 0.0f)
	{
		if (m_forceVel.x > 10.0f || m_forceVel.x < -10.0f)
		{
			m_forceVel.x -= transform.m_Friction.x * (abs(m_forceVel.x) / m_forceVel.x) * _dT * 100.0f;
		}
		else
			m_forceVel.x = 0.0f;

		if (m_forceVel.y > 10.0f || m_forceVel.y < -10.0f)
		{
			m_forceVel.y -= transform.m_Friction.y * (abs(m_forceVel.y) / m_forceVel.y) * _dT * 100.0f;
		}
		else
			m_forceVel.y = 0.0f;
	}

	//Clamp Acceleration
	float mag = sqrt(pow(m_externVel.x, 2) + pow(m_externVel.y, 2));
	if (mag > 600.0f)
	{
		m_externVel = (m_externVel / mag) * 600.0f;
	}

	//Clamp magnetic Speed
	mag = sqrt(pow(m_forceVel.x, 2) + pow(m_forceVel.y, 2));
	if (mag > 300.0f)
	{
		m_forceVel = (m_forceVel / mag) * 300.0f;
	}

	if (!m_disableControl)
		transform.m_Velocity = m_InputHandler->GetMovementVector() * m_speed + (m_externVel + m_forceVel);
	else
	{
 		transform.m_Velocity = (m_externVel + m_forceVel);

	}
	//Clamp Velocity
	

	//Update Position from velocity
	transform.m_Position += transform.m_Velocity * _dT;
	//Update sprite position
	GetSprite()->setPosition(transform.m_Position);
	m_circleIndicator.setPosition(transform.m_Position);
//	transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);

	if (m_DeathTimer != nullptr)
	{
		m_DeathTimer->Update(_dT);
	}
	DelayedDeathUpdate();
}

/***********************
* SetPlayerVector: creates a Vector of all the players
* @author: Neel Kolhe
* parameters: Vector
********************/
void player::SetPlayerVector(std::vector<player*>* _player)
{
	m_vPlayers = _player;			//pushes the players onto a vector for checking the player collision
}



/***********************
* SetBatteryVector: creates a Vector of all the Batteries
* @author: Himanshu Chawla
* parameters: Vector
********************/
void player::SetBatteryVector(std::vector<battery*>* _battery)
{
	m_vBatteries = _battery;
}

bool player::IsReady()
{
	return m_ready;
}

void player::SetReady(bool _ready)
{
	m_ready = _ready;
}

/***********************
* PlayerCollision: Checks Player Collision
* @author: Neel Kolhe
********************/
void player::PlayerCollision()
{
	float selfSpeed = Magnitude(transform.m_Velocity);		//sets the speed of the player
	for (auto i : *m_vPlayers)								//logs the opposing player
	{
		if (i != this && !i->GetWillDie())										//checks if the player is not the opposing
		{
			float MinDistance = GetTexture()->getSize().x * GetSprite()->getScale().x;		//calculates the minimum distance needed for collision between the two units

			sf::Vector2f DistanceCalc = i->transform.m_Position - transform.m_Position;		//calculates the distance between the two positions
			float Distance = sqrt(pow(DistanceCalc.x, 2) + pow(DistanceCalc.y, 2));			//gets the magnitude of the two positions


			float collSpeed = Magnitude(i->transform.m_Velocity);							//makes a float for the collspeed
			if (Distance <= MinDistance)					//if the two objects are colliding
			{
				DistanceCalc = DistanceCalc / Distance;		//gets the distance between the two units
				
				if (i->m_ability == battery::eAbility::turtle)
				{

					if (m_ability != battery::eAbility::turtle)
						//i->AddForce((transform.m_Velocity * 0.8f + DistanceCalc * selfSpeed * 0.8f - i->transform.m_Velocity * 0.8f)/10.0f);		
						std::cout << "";
					else
						i->AddForce(transform.m_Velocity * 1.6f + DistanceCalc * selfSpeed * 1.6f - i->transform.m_Velocity * 0.5f);		//Adds the bounce back effect on the two units Both are Turtle
				}
				else
				{
					if (m_ability != battery::eAbility::turtle)
						i->AddForce(transform.m_Velocity * 1.6f + DistanceCalc * selfSpeed * 1.6f - i->transform.m_Velocity * 0.1f);		//Adds the bounce back effect on the two units
					else
						i->AddForce((transform.m_Velocity * 1.6f + DistanceCalc * selfSpeed * 1.6f - i->transform.m_Velocity * 0.1f) * 10.0f);		//Adds the bounce back effect on the two units one is Turtle
					
				}
				if (!m_disableControl)
				{
					m_disableControl = true;
					i->m_disableControl = true;
					m_disableTimer = 0.8f;
				}
			}
			//std::cout << i->transform.m_Position.x << "\n";

		}
	}
}



/***********************
* PlayerCollision: Checks Battery Collision
* @author: Himanshu Chawla
********************/
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


/***********************
* BatteryImplementation: Implement Battery Function
* @author: Himanshu Chawla
* Parameters: deltaTimer
********************/
void player::BatteryImplementation(float _dt)
{
	m_abilityTimer -= _dt;
	
	switch (m_ability)
	{
	case battery::none:
		break;
	case battery::turtle:
	{
		m_speed = 2.5f;
	}
		break;
	case battery::magnetic:
	{
		//Magnetic Pull
		for (auto it : *m_vPlayers)
		{
			if (it != this)
			{
				float mag = Magnitude(transform.m_Position - it->transform.m_Position);
				//if(abs(transform.m_Position.x - it->transform.m_Position.x) < 500.0f && abs(transform.m_Position.y - it->transform.m_Position.y) < 500.0f)
					it->AddPowerForrce((transform.m_Position - it->transform.m_Position)/mag * 6.2f);
				
			}
		}
	}
		break;
	case battery::leaking:
		if (m_abilityTimer < 0.0f)
		{
			LeakingBattery();
		}
		break;
	default:
		break;
	}

	if (m_abilityTimer < 0.0f && m_ability != battery::eAbility::none)
	{
		m_ability = battery::eAbility::none;
		m_speed = 5.0f;
	}
}

/***********************
* LeakingBattery: Starts explosion process of leaking battery player.
* @author: William de Beer
********************/
void player::LeakingBattery()
{
	// Apply large force to all players in range.
	for (auto it : *m_vPlayers)
	{
		if (it != this)
		{
			float distance = Magnitude(transform.m_Position - it->transform.m_Position);
			if (distance < m_fExpRange)
			{
				it->AddForce(((it->transform.m_Position - transform.m_Position) / distance) * 10.0f);
				it->m_disableControl = true;
				it->m_disableTimer = 0.8f;
				it->m_bExphit = true;
			}
		}
	}

	// Make sprite invisible
	GetSprite()->setColor(sf::Color(0, 0, 0, 0));

	// Cease player control and movement
	m_disableControl = true;
	m_disableTimer = m_fDeathDelay;
	m_DeathTimer = new timer(m_fDeathDelay, 0.0f);
	m_powerForce = sf::Vector2f(0.0f, 0.0f);
	m_externVel = sf::Vector2f(0.0f, 0.0f);
	m_forceVel = sf::Vector2f(0.0f, 0.0f);

	m_bWillDie = true;
}

/***********************
* DelayedDeathUpdate: When in use will delay death for a set time. 
* @author: William de Beer
* @parameter: Delta time
********************/
void player::DelayedDeathUpdate()
{
	if (m_DeathTimer == nullptr)
		return;
	if (m_bWillDie && m_DeathTimer->IsFinished())
	{
		death();
		std::cout << "Player has died" << std::endl;
	}
}

/***********************
* DrawCircleIndicator: Draw area of effect indicator for leaking battery explosion.
* @author: William de Beer
* @parameter: Reference to render window
********************/
void player::DrawCircleIndicator(sf::RenderWindow& _window)
{
	// Only draw while leaking battery is in use.
	if (m_ability == battery::eAbility::leaking)
	{
		_window.draw(m_circleIndicator);
	}
}