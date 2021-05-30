#pragma once
#include "gameObject.h"
class battery :
	public gameObject
{
	
public:
	
	enum eAbility
{
	none,
	turtle,
	magnetic,
	leaking,
}m_ability;

	battery();
	battery(int ch, sf::Vector2f _position);
	~battery();
	
	float GetAbilityTimer();

private:
	float m_abilityTimer;
};

