#include "battery.h"

battery::~battery()
{

}

float battery::GetAbilityTimer()
{
	return m_abilityTimer;
}


battery::battery()
{
	SetSpriteFromFile("Assets/Batteries/Base.png");
	transform.m_Position = sf::Vector2f(300.0f, 500.0f);
	m_ability = none;
	m_abilityTimer = 50.0f;
}

//Constuctor
//Assigns Battery type
battery::battery(int ch, sf::Vector2f _position)
{
	switch (ch)
	{
	case 1:	//Turtle Battery
	{
		SetSpriteFromFile("Assets/Batteries/Turtle.png");
	}break;
	case 2:	//Magnetic Battery
	{
		SetSpriteFromFile("Assets/Batteries/Magnetic.png");
	}break;
	case 3:	//Leaking Battery
	{
		SetSpriteFromFile("Assets/Batteries/Leaking.png");
	}break;
	default:
		break;
	}
	transform.m_Position = _position;
	m_ability = (eAbility)ch;
	m_abilityTimer = 5.0f;

}