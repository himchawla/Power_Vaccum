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
	void Update(float _dT);

private:
	inputManager* m_InputHandler;
	float m_fFrictionMult = 1.0f;
	float m_fForceMult = 5.0f;
	float m_fMaxSpeed = 400.0f;
};

