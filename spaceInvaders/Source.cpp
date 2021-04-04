// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   Source.cpp
//  Description :   Main cpp
//  Author      :   Himanshu Chawala
//  Mail        :   *email here
// 
 // Library Includes 
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
 // Local Includes 
#include "gameObject.h"
#include "gameScene.h"
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

int main()
{

	srand(static_cast<unsigned int>(time(0)));

	sf::Sprite spr;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML");

	gameScene* scene = new gameScene();
	scene->Initialise(window);

	
	return 0;
}