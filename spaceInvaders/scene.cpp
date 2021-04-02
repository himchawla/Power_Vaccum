// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   scene.cpp
//  Description :   Parent class to all scenes.
//  Author      :   First Last
//  Mail        :   First.Last@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
 // This Include 
#include "scene.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 
scene::scene()
{
}

scene::~scene()
{
}

/***********************
* Render: Calls draw functions for scene.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void scene::Render(sf::RenderWindow& _window)
{
	_window.clear();

	DrawBackground(_window);
	DrawObjects(_window);
	DrawUI(_window);

	_window.display();
}

