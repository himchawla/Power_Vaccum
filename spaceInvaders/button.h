#pragma once
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   Button.h
//  Description :   The Button Class is 
// used as the interactable features within Scenes to allow the players to move through scenes or quit the game.
//  Author      :   Gervince Go 
//  Mail        :   Gervince.Go@mds.ac.nz
// 
 // Library Includes 
#include "gameObject.h"
#include "uiImage.h"
#include "timer.h"
#include "inputManager.h"
 // Library Includes 
#include <iostream>
 // Implementation
class button : public uiImage
{
	public:
		button();

	

		button(float x_pos, float y_pos, int _weight, std::string _path);
		virtual ~button();

		// Check If the Mouse is hovering over the Button
		void isMouseHere(sf::RenderWindow& window);

		
		sf::Text* GetButtonText();
		void setButtonText(std::string _textString, int _characterSize);

		sf::RectangleShape* GetRect();
		void SetRect(sf::RectangleShape* _rect);

		// Check if button is Clicked
		bool Clicked(); // return if button is clicked
		void Clicked(bool _clicked); // Set if button is clicked.


		void AssignImage(std::string _imageLoc);

		// Weight 
		int getWeight();
		void isSelected(bool _selected);

		bool isHovering();
		void SetColor(const sf::Color& _color);
		uiImage* m_buttonSprite;


	private:

		sf::RectangleShape* m_TempRect;
		sf::Vector2f m_2fPosition;
		sf::Text* m_buttonText;
		sf::Font m_arial;
		float m_fRotation = 0;
		int m_iWeight = 0; // Weight is which button this is designated on the scene.
		bool m_bIsClicked = false;
		bool m_bIsSelected = false;
		bool m_bIsHovering = false;


		sf::Vector2f m_v2ButtonSize = sf::Vector2f(300, 150);
		float m_delay;
};

