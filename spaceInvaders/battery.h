#pragma once
#include "gameObject.h"
#include"timer.h"
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
	timer* GetDestroyTimer();
	battery(int ch, sf::Vector2f _position);
	~battery();

	void Update(float _dT)
	{
		m_destroyTimer->Update(_dT);
		reinterpret_cast<gameObject*>(this)->Update(_dT);
	}
	
	float GetAbilityTimer();

private:
	timer *m_destroyTimer;
	float m_abilityTimer;
};

