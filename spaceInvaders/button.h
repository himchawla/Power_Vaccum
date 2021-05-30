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

		void isMouseHere(sf::RenderWindow& window);
		sf::RectangleShape* GetRect();
		void SetRect(sf::RectangleShape* _rect);
		bool Clicked();
		void Clicked(bool _clicked);
		void AssignImage(std::string _imageLoc);
		void Update(sf::RenderWindow& _window);
		// get UI Image.
		bool isClicked();
		int getWeight();
		void isSelected(bool _selected);

		bool isHovering();
		void SetColor(const sf::Color& _color);


	private:

		sf::RectangleShape* m_TempRect;
		sf::Vector2f m_2fPosition;
		float m_fRotation = 0;
		int m_iWeight = 0;
		bool m_bIsClicked = false;
		bool m_bIsSelected = false;
		bool m_bIsHovering = false;

		uiImage* m_buttonSprite;

		sf::Vector2f m_v2ButtonSize = sf::Vector2f(300, 150);
		float m_delay;
};

