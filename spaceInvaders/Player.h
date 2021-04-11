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




//Local includes
#include "gameObject.h"
#include <vector>

class player :
	public gameObject
{
public:
	player(int _player);
	~player();
	void addForce(sf::Vector2f dir);
	void Update(float _dT);
	void SetPlayerVector(std::vector<player*>* _player);

	//This needs to go in private variable once collisions are applied
	inputManager* m_InputHandler;

private:
	void PlayerCollision();
	std::vector<player*>* m_vPlayers;
};

#endif