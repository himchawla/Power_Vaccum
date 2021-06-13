#include "button.h"


button::button():uiImage(sf::Vector2f(0,0), "", false)
{
	if (!m_arial.loadFromFile("Assets/arial.ttf"))
	{
		// error...
	}

	m_buttonText->setFont(m_arial);
	m_TempRect = new sf::RectangleShape;
	

	m_TempRect->setSize(sf::Vector2f(m_v2ButtonSize));
	m_TempRect->setFillColor(sf::Color::White);
	m_TempRect->setOutlineThickness(2);
	m_TempRect->setOutlineColor(sf::Color::Black);
	m_TempRect->setPosition(0, 0);
	m_TempRect->setOrigin(m_v2ButtonSize.x * 0.5f, m_v2ButtonSize.y * 0.5f);
	
}

button::button(float x_pos, float y_pos, int _weight, std::string _path):uiImage(sf::Vector2f(x_pos, y_pos), _path + ".png", false)
{
	if (!m_arial.loadFromFile("Assets/arial.ttf"))
	{
		// error...
	}

	m_buttonText = new sf::Text();

	m_buttonText->setFont(m_arial);
	m_buttonText->setCharacterSize(50);
	m_buttonText->setString("Default");
	m_buttonText->setFillColor(sf::Color::Black);
	m_buttonText->setOrigin(m_v2ButtonSize.x * 0.5f, m_v2ButtonSize.y * 0.5f);
	m_buttonText->setPosition(x_pos + 25, y_pos + 45);

	m_TempRect = new sf::RectangleShape();

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
	if (m_buttonText != nullptr)
	{
		delete m_buttonText;
		m_buttonText = nullptr;
	}

	if (m_TempRect != nullptr)
	{
		delete m_TempRect;
		m_TempRect = nullptr;
	}

	if (m_buttonSprite != nullptr)
	{
		delete m_buttonSprite;
		m_buttonSprite = nullptr;
	}
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
	}


	// If the mouse is withi boundaries of the Node.
	if ((fMouseX < fButtonWidthX && fMouseX > fButtonPosX) &&
		(fMouseY < fButtonHeightY && fMouseY > fButtonPosY))
	{
		m_bIsHovering = true;
		GetSprite()->setColor(sf::Color(128, 128, 128));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m_bIsSelected = true;
			GetSprite()->setColor(sf::Color::Green);
			//m_TempRect->setFillColor(sf::Color::Blue);
		}
		
		else if (m_bIsSelected == true)
		{
			GetSprite()->setColor(sf::Color::Green);
			m_bIsClicked = true;
		}
	}
	else
	{
		m_bIsHovering = false;
		isSelected(false);
		GetSprite()->setColor(sf::Color::White);
	}


}

void button::setButtonText(std::string _textString, int _characterSize)
{
	m_buttonText->setCharacterSize(_characterSize);
	m_buttonText->setString(_textString);
}

sf::Text* button::GetButtonText()
{
	return m_buttonText;
}

void button::AssignImage(std::string _imageLoc)
{
	if (m_buttonSprite != nullptr)
	{
		delete m_buttonSprite;
		m_buttonSprite = nullptr;
	}
	m_buttonSprite = new uiImage(m_TempRect->getPosition(), _imageLoc, false);
}

void button::isSelected(bool _isSelected)
{
	m_bIsSelected = _isSelected;
}

bool button::isHovering()
{
	return m_bIsHovering;
}

void button::SetColor(const sf::Color& _color)
{
	GetSprite()->setColor(_color);

}

sf::RectangleShape* button::GetRect()
{
	return m_TempRect;
}

void button::SetRect(sf::RectangleShape* _rect)
{
	m_TempRect = _rect;
}

bool button::Clicked()
{
	return (m_bIsClicked);
}

void button::Clicked(bool _clicked)
{
	m_bIsClicked = _clicked;
}



int button::getWeight()
{
	return (m_iWeight);
}