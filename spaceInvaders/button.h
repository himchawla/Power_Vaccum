#pragma once
#include "gameObject.h"
#include "uiImage.h"
#include "timer.h"
#include "inputManager.h"
#include <iostream>


class button
{
	public:
		button();
		
		button(float x_pos, float y_pos, int _weight);
		virtual ~button();
		void Update(float _dT);

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

