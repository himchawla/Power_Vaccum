#include "button.h"


button::button()
{
	m_TempRect = new sf::RectangleShape;

	m_TempRect->setSize(sf::Vector2f(m_v2ButtonSize));
	m_TempRect->setFillColor(sf::Color::White);
	m_TempRect->setOutlineThickness(2);
	m_TempRect->setOutlineColor(sf::Color::Black);
	m_TempRect->setPosition(0, 0);
	m_TempRect->setOrigin(m_v2ButtonSize.x * 0.5f, m_v2ButtonSize.y * 0.5f);
}

// Weight is how we determine which button is associated with what.
button::button(float x_pos, float y_pos, int _weight)
{
	m_TempRect = new sf::RectangleShape;

	m_TempRect->setSize(sf::Vector2f(m_v2ButtonSize));
	m_TempRect->setFillColor(sf::Color::White);
	m_TempRect->setOutlineThickness(2);
	m_TempRect->setOutlineColor(sf::Color::Black);
	m_TempRect->setPosition(x_pos, y_pos);
	m_TempRect->setOrigin(m_v2ButtonSize.x * 0.5f, m_v2ButtonSize.y * 0.5f);
	m_iWeight = _weight;
}


button::~button()
{

}

void button::isMouseHere(sf::RenderWindow& window)
{
	float fMouseX = sf::Mouse::getPosition(window).x;
	float fMouseY = sf::Mouse::getPosition(window).y;

	float fButtonPosX = m_TempRect->getPosition().x - ((m_TempRect->getLocalBounds().width / 2));
	float fButtonPosY = m_TempRect->getPosition().y - ((m_TempRect->getLocalBounds().height / 2));

	float fButtonWidthX = fButtonPosX + (m_TempRect->getLocalBounds().width);
	float fButtonHeightY = fButtonPosY + (m_TempRect->getLocalBounds().height);

	if (m_bIsClicked == true)
	{
		m_TempRect->setFillColor(sf::Color::Blue);
	}


	// If the mouse is withi boundaries of the Node.
	if ((fMouseX < fButtonWidthX && fMouseX > fButtonPosX) &&
		(fMouseY < fButtonHeightY && fMouseY > fButtonPosY))
	{

		isSelected(true);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			std::cout << "This is True" << std::endl;
			m_bIsClicked = true;
			
		}
		else if (m_bIsSelected == true)
		{
			m_TempRect->setFillColor(sf::Color::Red);

		}


	}
	else
	{

		isSelected(false);
		m_TempRect->setFillColor(sf::Color::White);
	}


}

void button::isSelected(bool _isSelected)
{
	m_bIsSelected = _isSelected;
}

sf::RectangleShape* button::GetRect()
{
	return m_TempRect;
}

void button::SetRect(sf::RectangleShape* _rect)
{
	m_TempRect = _rect;
}

bool button::isClicked()
{
	return (m_bIsClicked);
}

int button::getWeight()
{
	return (m_iWeight);
}