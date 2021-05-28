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
void inputManager::NormalizeClamp(sf::Vector2f& _vec)
{
	float mag = sqrt(pow(_vec.x, 2) + pow(_vec.y, 2));
	if (mag > 100.0f)
	{
		_vec = (_vec / mag) * 100.0f;
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
	// For using keyboard controls while debugging
	#pragma region Debug-Controller->Keyboard
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		SetUsingKeyboard(0, true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		SetUsingKeyboard(1, true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		SetUsingKeyboard(2, true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		SetUsingKeyboard(3, true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		SetUsingKeyboard(3, false);
	}
	#pragma endregion

	sf::Vector2f result(0, 0);

	if (usingKeyboard[_player]) // Keyboard inputs
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			result.x -= 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			result.x += 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			result.y += 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			result.y -= 100;

		NormalizeClamp(result);

		return result;
	}

	// Controller inputs
	result.x = sf::Joystick::getAxisPosition(_player, sf::Joystick::X);
	result.y = sf::Joystick::getAxisPosition(_player, sf::Joystick::Y);
	
	// Deadzone fix
	if (abs(result.x) < 15.0f)
	{
		result.x = 0;
	}
	if (abs(result.y) < 15.0f)
	{
		result.y = 0;
	}

	NormalizeClamp(result);

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


bool inputManager::GetKeyboardButton(int _button)
{
	if (m_iPlayerIndex == -1)
	{
		std::cout << "Error: Input manager recieved no player index." << std::endl;
		return false;
	}
	return GetKeyboardButton(_button, m_iPlayerIndex);
}

bool inputManager::GetKeyboardButton(int _button, int _player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		std::cout << "Player " << _player << " pressed button " << _button << "!" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}