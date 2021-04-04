#ifndef __SCENE_H__
#define __SCENE_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   scene.h
//  Description :   Parent class to all scenes.
//  Author      :   First Last
//  Mail        :   First.Last@mds.ac.nz
// 
 // Library Includes 
#include <SFML/Graphics.hpp>
 // Local Includes 
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 
class scene
{
public:
	scene();
	virtual ~scene();
	virtual void Initialise(sf::RenderWindow& _window) = 0;
protected:
	virtual void MainLoop(sf::RenderWindow& _window) = 0;
	virtual void Render(sf::RenderWindow& _window);
	virtual void Update(sf::RenderWindow& _window, float _dT) = 0;
	virtual void DrawBackground(sf::RenderWindow& _window) = 0;
	virtual void DrawObjects(sf::RenderWindow& _window) = 0;
	virtual void DrawUI(sf::RenderWindow& _window) = 0;
};
#endif
