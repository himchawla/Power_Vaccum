#include<SFML/System.hpp>
#include<SFML/Window.hpp>

#pragma once



class inputManager
{
public:
	struct JoystickAxis 
	{
		std::string m_KeyName;
		sf::Joystick::Axis axis = sf::Joystick::PovX;
	};
};

