// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   gameObject.h
//  Description :   Parent object for all gameobjects in game.
//  Author      :   William de Beer | Himanshu Chawla
//  Mail        :   William.Beer@mds.ac.nz | himanshu.chawla@mds.ac.nz
// 
 // Library Includes 
#include <math.h>
#include <iostream>
 // Local Includes 
 // This Include 
#include "gameObject.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 


gameObject::gameObject()
{
	transform.m_Mass = 1.0f;
	transform.m_Force = sf::Vector2f(0.0f, 0.0f);
	transform.m_Friction = sf::Vector2f(10.0f, 10.0f);
	transform.m_Position = sf::Vector2f(100.0f, 100.0f);
	enabled = true;
	m_Sprite = new sf::Sprite;
	m_Texture = new sf::Texture;
}

gameObject::~gameObject()
{
	delete m_Sprite;
	delete m_Texture;
}

/***********************
* Update: Calculates the physics for the gameObject
* @author: Himanshu Chawla
* @parameter: deltaTime
* @return: N/A
********************/
void gameObject::Update(float _dT)
{	
	transform.m_Velocity += transform.m_Acceleration * _dT;

	transform.m_Position += transform.m_Velocity * _dT;

	transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);

	m_Sprite->setPosition(transform.m_Position);
}

void gameObject::Draw(sf::RenderWindow& _window)
{
	if (enabled && m_Sprite != nullptr)
	{
		_window.draw(*m_Sprite);
		
	}
}

// Get magnitude
float gameObject::Magnitude(sf::Vector2f _vec)
{
	return sqrt(pow(_vec.x, 2) + pow(_vec.y, 2));
}

//Get Sprite
sf::Sprite* gameObject::GetSprite()
{
	return m_Sprite;
}

//Set Sprite
void gameObject::SetSprite(sf::Sprite* _sprite)
{
	m_Sprite = _sprite;
}

//Get Texture
sf::Texture* gameObject::GetTexture()
{
	return m_Texture;
}

//Set Texture
void gameObject::SetTexture(sf::Texture* _texture)
{
	m_Texture = _texture;
}


/***********************
* Update: Sets the sprite and Texture
* @author: Himanshu Chawla
* @parameter: address
* @return: N/A
********************/
void gameObject::SetSpriteFromFile(std::string _address)
{
	GetTexture()->loadFromFile(_address);
	GetSprite()->setTexture(*GetTexture());
	GetSprite()->setScale(64.0f / GetTexture()->getSize().x, 64.0f / GetTexture()->getSize().y);
	GetSprite()->setOrigin(GetTexture()->getSize().x * 0.5f, GetTexture()->getSize().y * 0.5f);
}

void gameObject::Destroy()
{
	enabled = false;
}
