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



/***********************
* Update: Updates Player Position.
* @author: Himanshu Chawla
* @parameter: Delta time.
********************/
void Player::Update(float _dT)
{
	// Temp local variables
	float frictionMult = 1.0f;
	float forceMult = 1.0f;

	// Get force and acceleration
	transform.m_Force = m_InputHandler->GetMovementVector() * forceMult;
	transform.m_Accelaration = (transform.m_Force / transform.m_Mass);

	// Clamp acceleration
	float mag = sqrt(pow(transform.m_Accelaration.x, 2) + pow(transform.m_Accelaration.y, 2));
	if (mag > 100.0f)
	{
		transform.m_Accelaration = (transform.m_Accelaration / mag) * 100.0f;
	}

	// Apply acceleration
	transform.m_Velocity += transform.m_Accelaration * _dT;

	// Apply friction if not applying force
	if (mag == 0)
	{
		transform.m_Velocity -= (transform.m_Velocity / 1.0f) * transform.m_Mass * frictionMult * _dT;
	}

	// Clamp velocity
	mag = sqrt(pow(transform.m_Velocity.x, 2) + pow(transform.m_Velocity.y, 2));
	if (mag > 100.0f)
	{
		transform.m_Velocity = (transform.m_Velocity / mag) * 100.0f;
	}

	// Apply velocity
	transform.m_Position += transform.m_Velocity * _dT;
	GetSprite()->setPosition(transform.m_Position);



	//	transform.m_Force = sf::Vector2f(0.0f, 0.0f);


	//std::cout << transform.m_Velocity.x << ", " << transform.m_Velocity.y << std::endl;

	//transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);



	//transform.m_Velocity += m_InputHandler->GetMovementVector() * 5.0f;

	//transform.m_Velocity += transform.m_Accelaration * _dT;


	////	transform.m_Force = sf::Vector2f(0.0f, 0.0f);


	//transform.m_Position += transform.m_Velocity * _dT;

	//transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);
}
