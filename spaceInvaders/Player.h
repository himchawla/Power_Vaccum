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


#pragma once

//Local includes
#include "gameObject.h"
#include <vector>

class Player :
	public gameObject
{
public:
	Player(int _player);
	~Player();
	void addForce(sf::Vector2f dir);
	void Update(float _dT);
	void SetPlayerVector(std::vector<Player*>* _player);

	inputManager* m_InputHandler;

private:
	std::vector<Player*>* m_vPlayers;

	void PlayerCollision();
};

