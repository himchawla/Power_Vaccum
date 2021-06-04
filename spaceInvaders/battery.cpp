#include "battery.h"

battery::~battery()
{
	if (m_destroyTimer != nullptr)
	{
		delete m_destroyTimer;
		m_destroyTimer = 0;
	}
}


void battery::Update(float _dT)
{
	m_destroyTimer->Update(_dT);
	if(m_destroyTimer->GetTime() < 2.0f)
	{
		sf::Color color = GetSprite()->getColor();
		GetSprite()->setColor(sf::Color(color.r, color.g, color.b, (m_destroyTimer->GetTime() / 2) * 255));
	}
	gameObject::Update(_dT);
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