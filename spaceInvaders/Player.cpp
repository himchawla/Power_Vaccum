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

	m_fFrictionMult = 1.0f;
	m_fForceMult = 5.0f;
	m_fMaxSpeed = 400.0f;

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



/***********************
* Update: Updates Player Position.
* @author: Himanshu Chawla | William de Beer
* @parameter: Delta time.
********************/
void Player::Update(float _dT)
{
	// Get force and acceleration
	transform.m_Force = m_InputHandler->GetMovementVector() * m_fForceMult;
	transform.m_Accelaration = (transform.m_Force / transform.m_Mass);

	// Apply acceleration
	transform.m_Velocity += transform.m_Accelaration * _dT;

	// Apply friction if not applying force
	float mag = sqrt(pow(transform.m_Accelaration.x, 2) + pow(transform.m_Accelaration.y, 2));
	if (mag == 0)
	{
		transform.m_Velocity -= (transform.m_Velocity / 1.0f) * transform.m_Mass * m_fFrictionMult * _dT;
	}

	// Clamp velocity
	mag = sqrt(pow(transform.m_Velocity.x, 2) + pow(transform.m_Velocity.y, 2));
	if (mag > m_fMaxSpeed)
	{
		transform.m_Velocity = (transform.m_Velocity / mag) * m_fMaxSpeed;
	}

	// Apply velocity
	transform.m_Position += transform.m_Velocity * _dT;
	GetSprite()->setPosition(transform.m_Position);
}
