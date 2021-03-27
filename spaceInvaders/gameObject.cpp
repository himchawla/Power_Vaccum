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
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
 // This Include 
#include "gameObject.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 


gameObject::gameObject()
{
}

gameObject::~gameObject()
{
}

void gameObject::Update(float _dT)
{
	m_TempCirc->setPosition(m_2fPosition);
}

sf::Vector2f gameObject::GetPosition()
{
	return m_2fPosition;
}

void gameObject::SetPosition(sf::Vector2f _position)
{
	m_2fPosition = _position;
}

sf::Sprite* gameObject::GetSprite()
{
	return m_Sprite;
}

void gameObject::SetSprite(sf::Sprite* _sprite)
{
	m_Sprite = _sprite;
}

sf::CircleShape* gameObject::GetCircle()
{
	return m_TempCirc;
}

void gameObject::SetCircle(sf::CircleShape* _circle)
{
	m_TempCirc = _circle;
}
