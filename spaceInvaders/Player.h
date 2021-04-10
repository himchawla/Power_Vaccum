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


class Player :
	public gameObject
{
public:
	Player(int _player);
	~Player();
	void addForce(sf::Vector2f dir);
	void Update(float _dT);

	inputManager* m_InputHandler;

private:



};

