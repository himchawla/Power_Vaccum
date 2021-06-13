#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class text
{
public:
	text(sf::Vector2f _position, std::string _text = "", std::string _fontPath = "Assets/arial.ttf",
	     int _charSize = 500.0f, sf::Color _fillColor = sf::Color::Black);

	sf::Text* GetText();

	void SetString(std::string _text);

	void SetSize(int _charSize);

	void Render(sf::RenderWindow& _window);

private:
	sf::Font m_font;
	sf::Text *m_text;
};

