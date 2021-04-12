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

private:
	void PlayerCollision();
	std::vector<player*>* m_vPlayers;
	inputManager* m_InputHandler;
};

#endif