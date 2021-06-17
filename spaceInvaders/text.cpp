#include "text.h"

text::text(sf::Vector2f _position, std::string _text, std::string _fontPath, int _charSize, sf::Color _fillColor)
{
	m_text = new sf::Text();
	m_font.loadFromFile(_fontPath);
	m_text->setFont(m_font);
	m_text->setFillColor(_fillColor);
	m_text->setPosition(_position - sf::Vector2f(_charSize / 3, _charSize / 2));
	m_text->setString(_text);
	m_text->setCharacterSize(_charSize);
}

/***********************
* GetText: Returns text
* @author: Himanshu Chawla
* @return: 
********************/
auto text::GetText() -> sf::Text*
{
	return m_text;
}

/***********************
* SetText: Setter for text string
* @author: Himanshu Chawla
* @return: 
********************/
auto text::SetString(std::string _text) -> void
{
	m_text->setString(_text);
}

/***********************
* SetSize: Sets the size of text 
* @author: Himanshu Chawla
* @return: N/A
********************/
void text::SetSize(int _charSize)
{
	m_text->setCharacterSize(_charSize);
}


/***********************
* Render: Renders the Text
* @author: Himanshu Chawla
* @return: N/A
********************/
void text::Render(sf::RenderWindow& _window)
{
	
	_window.draw(*m_text);
}


