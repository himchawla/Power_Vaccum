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

class player :
	public gameObject
{
public:
	player(int _player);
	~player();
	void AddForce(sf::Vector2f _dir);
	void Update(float _dT);
	void SetPlayerVector(std::vector<player*>* _player);
	void SetBatteryVector(std::vector<battery*>* _player);


	battery::ability m_ability;

private:
	
	float m_abilityTimer;
	inputManager* m_InputHandler;
	void PlayerCollision();
	void BatteryCollision();
	std::vector<player*>* m_vPlayers;
	std::vector<battery*>* m_vBatteries;

};

#endif