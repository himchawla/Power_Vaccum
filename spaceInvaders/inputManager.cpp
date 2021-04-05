// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   inputManager.cpp
//  Description :   Class which manages all player inputs
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <iostream>
 // Local Includes 
 // This Include 
#include "inputManager.h"
#include <math.h>
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

bool inputManager::usingKeyboard[4] = { true };

sf::Vector2f Normalize(sf::Vector2f vec)
{
	vec.x = vec.x / pow((pow(vec.x, 2) + pow(vec.y, 2)), 1 / 2);
	vec.y = vec.y / pow((pow(vec.x, 2) + pow(vec.y, 2)), 1 / 2);
	return vec;
}
inputManager::inputManager()
{
	m_iPlayerIndex = -1;
}

inputManager::inputManager(int _player)
{
	m_iPlayerIndex = _player;
}

inputManager::~inputManager()
{
}

/***********************
* BindPlayer: Bind the player index to the input manager.
* @author: William de Beer
* @parameter: Parameters
* @return: Return values
********************/
void inputManager::BindPlayer(int _player)
{
	m_iPlayerIndex = _player;
}


/***********************
* GetMovementVector: Obtains movement vector from joystick input.
* @author: William de Beer
* @return: 2D Vector
********************/
sf::Vector2f inputManager::GetMovementVector()
{
	if (m_iPlayerIndex == -1)
	{
		std::cout << "Error: Input manager recieved no player index." << std::endl;
		return sf::Vector2f(0, 0);
	}
	return GetMovementVector(m_iPlayerIndex);
}

/***********************
* GetControllerButton: Returns bool value indicating whether or not button is being pressed.
* @author: William de Beer
* @parameter: Button number
* @return: Button state
********************/
bool inputManager::GetControllerButton(int _button)
{
	if (m_iPlayerIndex == -1)
	{
		std::cout << "Error: Input manager recieved no player index." << std::endl;
		return false;
	}
	return GetControllerButton(_button, m_iPlayerIndex);
}

/***********************
* SetUsingKeyboard: Sets boolean indicating whether it is using the keyboard.
* @author: William de Beer
* @parameter: Is Using Boolean
********************/
void inputManager::SetUsingKeyboard(bool _isUsing)
{
	SetUsingKeyboard(m_iPlayerIndex, _isUsing);
}

/***********************
* GetMovementVector: Obtains movement vector from joystick input.
* @author: William de Beer
* @parameter: Player index
* @return: 2D Vector
********************/
sf::Vector2f inputManager::GetMovementVector(int _player)
{
	float x = 0;
	float y = 0;

	if (usingKeyboard[_player])
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			x -= 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			x += 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			y += 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			y -= 100;


		
		return Normalize(sf::Vector2f(x, y)) * 100.0f;
	}
	else
	{

		x = sf::Joystick::getAxisPosition(_player, sf::Joystick::X);
		y = sf::Joystick::getAxisPosition(_player, sf::Joystick::Y);
		
		

	}
	
	return sf::Vector2f(x, y);
}

/***********************
* GetControllerButton: Returns bool value indicating whether or not button is being pressed.
* @author: William de Beer
* @parameter: Button number, player index
* @return: Button state
********************/
bool inputManager::GetControllerButton(int _button, int _player)
{
	if (sf::Joystick::isButtonPressed(_player, _button))
	{
		std::cout << "Player " << _player << " pressed button " << _button << "!" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

/***********************
* SetUsingKeyboard: Sets boolean indicating whether it is using the keyboard.
* @author: William de Beer
* @parameter: Player index, Is Using Boolean
********************/
void inputManager::SetUsingKeyboard(int _player, bool _isUsing)
{
	for (int i = 0; i < 4; i++)
	{
		usingKeyboard[i] = false;
	}
	usingKeyboard[_player] = _isUsing;
}