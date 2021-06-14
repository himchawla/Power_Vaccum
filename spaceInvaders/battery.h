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
	timer* GetPickupTimer();
	battery(int ch, sf::Vector2f _position);
	~battery();

	void Update(float _dT);

	float GetAbilityTimer();

 	bool m_checkPickup;
private:
	timer *m_destroyTimer;
	float m_abilityTimer;
	timer* m_pickupTimer;
};

