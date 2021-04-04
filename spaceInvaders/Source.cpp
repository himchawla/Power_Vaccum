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

	gameObject* temp = new gameObject();
	temp->SetCircle(new sf::CircleShape(100.0f));
	temp->GetCircle()->setFillColor(sf::Color::Green);
	sf::Clock clock;
	//temp->transform.m_Accelaration = sf::Vector2f(0.02f, 0.0f);
	temp->transform.m_Position = (sf::Vector2f(800,800));

	sf::Keyboard::Key key = sf::Keyboard::Escape;

	//Game Loop
	while (window.isOpen())
	{
		sf::Event event;

		// Getting delta time
		float deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();



		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code != sf::Keyboard::Space)
			{
				key = event.key.code;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code != sf::Keyboard::Space)
			{
				key = sf::Keyboard::Add;
			}

			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				key = sf::Keyboard::Space;
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		




		switch (key)
		{
		
		case sf::Keyboard::A:
		{
			temp->transform.m_Velocity = sf::Vector2f(-100.0f, 0.0f);
		}
			break;
		
		case sf::Keyboard::D:
			break;
		case sf::Keyboard::E:
			break;
		
		case sf::Keyboard::S:
			break;
		
		case sf::Keyboard::W:
			break;
		
		case sf::Keyboard::Space:
		{
			temp->transform.m_Force = sf::Vector2f(2.0f, 0.0f);
		}
			break;
		
		
		
		default:
		{
			temp->transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);
		}
			break;
		}

		temp->Update(deltaTime);


	window.clear();
	window.draw(*temp->GetCircle());
	window.display();
	}

	return 0;
}