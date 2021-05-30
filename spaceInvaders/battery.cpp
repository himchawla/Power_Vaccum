#include "battery.h"

battery::~battery()
{
	delete m_destroyTimer;
}


void battery::Update(float _dT)
{
	m_destroyTimer->Update(_dT);
	reinterpret_cast<gameObject*>(this)->Update(_dT);
}

float battery::GetAbilityTimer()
{
	return m_abilityTimer;
}


battery::battery()
{
	m_destroyTimer = new timer(10.0f, 0.0f);
	SetSpriteFromFile("Assets/Batteries/Base.png");
	transform.m_Position = sf::Vector2f(300.0f, 500.0f);
	m_ability = none;
	m_abilityTimer = 50.0f;
	
}

timer* battery::GetDestroyTimer()
{
	return m_destroyTimer;
}

//Constuctor
//Assigns Battery type
battery::battery(int ch, sf::Vector2f _position)
{
	m_destroyTimer = new timer(20.0f, 0.0f);

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