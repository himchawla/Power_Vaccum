// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2019 Media Design School 
// 
//  File Name   :	Source.cpp
//  Description :	Implementation for sprite class
//  Author      :   Himanshu Chawla
//  Mail        :   Himanshu.Cha8420@mediadesign.mail.nz 
// 
 // Implementation 


#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>





int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML");

	
	//Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}
	window.display();
	}

	return 0;
}