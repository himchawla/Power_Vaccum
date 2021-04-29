#ifndef __PLAYER_H__
#define __PLAYER_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   Player.h
//  Description :   Player class inherits from the gameObject class
//  Author      :   Himanshu Chawla
//  Mail        :   himanshu.chawla@mds.ac.nz
// 
 // Library Includes 
#include <vector>
 //Local includes
#include "gameObject.h"
#include "battery.h"

class player :
	public gameObject
{
public:
	player(int _player, b2World& _world);
	~player();
	void AddForce(sf::Vector2f _dir);
	float m_speed = 10.0f;
	void Update(float _dT);
	void SetPlayerVector(std::vector<player*>* _player);
	void SetBatteryVector(std::vector<battery*>* _player);

	void collide() { }
	void endContact(){}
	battery::ability m_ability;

private:
	
	sf::Vector2f m_externVel = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f m_forceVel = sf::Vector2f(0.0f, 0.0f);

	float m_abilityTimer;
	inputManager* m_InputHandler;
	void PlayerCollision();
	void BatteryCollision();
	void BatteryImplementation(float _dt);
	std::vector<player*>* m_vPlayers;
	std::vector<battery*>* m_vBatteries;

	
};

#endif