#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   inputManager.h
//  Description :   Class which manages all player inputs
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
 // Local Includes 
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

class inputManager
{
public:
	inputManager();
	inputManager(int _player);
	~inputManager();

	void BindPlayer(int _player);

	// Attached Input manager functions
	sf::Vector2f GetMovementVector();
	bool GetControllerButton(int _button);
	void SetUsingKeyboard(bool _isUsing);

	// Static Input manager functions
	static sf::Vector2f GetMovementVector(int _player);
	static bool GetControllerButton(int _button, int _player);
	static void SetUsingKeyboard(int _player, bool _isUsing);

	static void NormalizeClamp(sf::Vector2f& _vec);
private: 
	int m_iPlayerIndex;
	static bool usingKeyboard[4];
};

#endif