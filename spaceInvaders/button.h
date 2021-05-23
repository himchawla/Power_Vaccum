#pragma once
#include "gameObject.h"
#include "uiImage.h"
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
		bool isClicked();
		int getWeight();




	private:

		sf::RectangleShape* m_TempRect;
		sf::Vector2f m_2fPosition;
		float m_fRotation = 0;
		int m_iWeight = 0;
		bool m_bIsClicked = false;

		sf::Vector2f m_v2ButtonSize = sf::Vector2f(300, 150);


};

