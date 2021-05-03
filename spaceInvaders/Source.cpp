// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   Source.cpp
//  Description :   Main 
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz 
// 
 // Library Includes 
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
 // Local Includes 
#include "gameObject.h"
#include "gameScene.h"
#include "sceneManager.h"
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

int main()
{
	// Seed rng
	srand(static_cast<unsigned int>(time(0)));

	// Create window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Power Vacuum!");

	// Create initial scene
	sceneManager::SetScene(new gameScene());
	sceneManager::Update(window);
	sceneManager::Shutdown();

	return 0;
}