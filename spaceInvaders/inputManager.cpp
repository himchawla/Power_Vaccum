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
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

bool inputManager::usingKeyboard[4] = { false };

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

sf::Vector2f inputManager::GetRightVector()
{
	if (m_iPlayerIndex == -1)
	{
		std::cout << "Error: Input manager recieved no player index." << std::endl;
		return sf::Vector2f(0, 0);
	}
	return GetRightVector(m_iPlayerIndex);
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
* Normalize: Normalizes a given vector
* @author: Himanshu Chawla
* @parameter: Vector to normalize
* @return: N\A
********************/
void inputManager::Normalize(sf::Vector2f& vec)
{
	float mag = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
	if (mag > 100.0f)
	{
		vec = (vec / mag) * 100.0f;
	}
}

/***********************
* GetMovementVector: Obtains movement vector from joystick input.
* @author: William de Beer | Himanshu Chawla
* @parameter: Player index
* @return: 2D Vector
********************/
sf::Vector2f inputManager::GetMovementVector(int _player)
{

	#pragma region Debug-Controller->Keyboard
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		usingKeyboard[0] = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		usingKeyboard[1] = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		usingKeyboard[2] = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		usingKeyboard[3] = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		usingKeyboard[0] = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	{
		usingKeyboard[1] = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
	{
		usingKeyboard[2] = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	{
		usingKeyboard[3] = false;
	}
	#pragma endregion


	sf::Vector2f result(0, 0);

	if (usingKeyboard[_player])
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			result.x -= 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			result.x += 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			result.y += 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			result.y -= 100;

		Normalize(result);

		return result;
	}

	result.x = sf::Joystick::getAxisPosition(_player, sf::Joystick::X);
	result.y = sf::Joystick::getAxisPosition(_player, sf::Joystick::Y);
	
	//std::cout << result.x << "\n";

	if (result.x < 15.0f && result.x > -15.0f)
	{
		result.x = 0;
	}
	

	if (result.y < 15.0f && result.y > -15.0f)
	{
		result.y = 0;
	}

	Normalize(result);



	return result;
}

sf::Vector2f inputManager::GetRightVector(int _player)
{


	sf::Vector2f result(0, 0);

	if (usingKeyboard[_player])
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			result.x -= 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			result.x += 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			result.y += 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			result.y -= 100;

		Normalize(result);

		return result;
	}

	result.x = sf::Joystick::getAxisPosition(_player, sf::Joystick::U);
	result.y = sf::Joystick::getAxisPosition(_player, sf::Joystick::V);

	std::cout << result.x << "\n";
	if (result.x < 15.0f && result.x > -15.0f)
	{
		result.x = 0;
	}


	if (result.y < 15.0f && result.y > -15.0f)
	{
		result.y = 0;
	}

	Normalize(result);



	return result;
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