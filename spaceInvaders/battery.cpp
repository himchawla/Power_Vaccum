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
	m_ability = turtle;
	m_abilityTimer = 50.0f;
}

void battery::Destroy()
{

}
