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

	gameObject* temp = new gameObject();
	temp->SetCircle(new sf::CircleShape(100.0f));
	temp->GetCircle()->setFillColor(sf::Color::Green);
	sf::Clock clock;
	temp->SetPosition(sf::Vector2f(800,800));

	//Game Loop
	while (window.isOpen())
	{
		sf::Event event;

		// Getting delta time
		float deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}

		temp->Update(deltaTime);


	window.clear();
	window.draw(*temp->GetCircle());
	window.display();
	}

	return 0;
}