#pragma once
#include "gameObject.h"
class battery :
	public gameObject
{
	
public:
	
	enum ability
{
	none,
	turtle,
	magnetic,
	leaking,
}m_ability;

	battery();
	battery(int ch, sf::Vector2f _position);
	void Destroy();
	~battery();
	
	float GetAbilityTimer();

private:
	float m_abilityTimer;
};

