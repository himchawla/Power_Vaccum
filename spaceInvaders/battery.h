// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   Battery.h
//  Description :   The Button Class is 
// used as the interactable features within Scenes to allow the players to move through scenes or quit the game.
//  Author      :   Himanshu Chawla | Neel
//  Mail        :   Himanshu.Chawla@mds.ac.nz
// 
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

