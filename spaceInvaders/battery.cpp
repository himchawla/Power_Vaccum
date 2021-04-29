#include "battery.h"

battery::~battery()
{

}

float battery::GetAbilityTimer()
{
	return m_abilityTimer;
}

battery::battery(b2World& _world):gameObject(_world)
{
	SetSpriteFromFile("Assets/Batteries/Base.png");
	//transform.m_Position = sf::Vector2f(300.0f, 500.0f);
	m_ability = magnetic;
	m_abilityTimer = 5.0f;
}

void battery::Destroy()
{

}
