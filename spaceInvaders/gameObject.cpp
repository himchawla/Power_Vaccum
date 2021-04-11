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
 // Local Includes 
 // This Include 
#include "gameObject.h"
#include <math.h>
#include<iostream>
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

float gameObject::Magnitude(sf::Vector2f vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}

gameObject::gameObject(int player)
{
	transform.m_Mass = 1.0f;
	transform.m_Force = sf::Vector2f(0.0f, 0.0f);
	transform.m_Friction = sf::Vector2f(1.0f, 1.0f);
	transform.m_Position = sf::Vector2f(100.0f, 100.0f);

	m_Sprite = new sf::Sprite;
	m_Texture = new sf::Texture;
}

gameObject::gameObject()
{
	transform.m_Mass = 1.0f;
	transform.m_Force = sf::Vector2f(0.0f, 0.0f);
	transform.m_Friction = sf::Vector2f(1.0f, 1.0f);
	transform.m_Position = sf::Vector2f(100.0f, 100.0f);

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

	transform.m_Velocity += transform.m_Accelaration * _dT;


	//	transform.m_Force = sf::Vector2f(0.0f, 0.0f);


	transform.m_Position += transform.m_Velocity * _dT;

	transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);

	transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);
	m_Sprite->setPosition(transform.m_Position);
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

//Get Circle
sf::CircleShape* gameObject::GetCircle()
{
	return m_TempCirc;
}

//Set Circle
void gameObject::SetCircle(sf::CircleShape* _circle)
{
	m_TempCirc = _circle;
}

//Get Texture
sf::Texture* gameObject::GetTexture()
{
	return m_Texture;
}

//Set Texture
void gameObject::setTexture(sf::Texture* _texture)
{
	m_Texture = _texture;
}
