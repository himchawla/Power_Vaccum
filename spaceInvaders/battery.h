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
	void Destroy();
	~battery();
	
	float GetAbilityTimer();

private:
	float m_abilityTimer;
};

