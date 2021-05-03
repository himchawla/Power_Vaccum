#include "uiImage.h"

uiImage::uiImage(sf::Vector2f _pos, std::string _texLoc)
{
	transform.m_Position = _pos;

	// Load texture
	GetTexture()->loadFromFile(_texLoc);

	// Configure sprite
	GetSprite()->setTexture(*GetTexture());
	transform.m_Mass = 0.0f;
	transform.m_Force = sf::Vector2f(0.0f, 0.0f);
	transform.m_Friction = sf::Vector2f(0.0f, 0.0f);
	
	tempClock = 0;
}

uiImage::~uiImage()
{
}

void uiImage::Update(float _dt)
{
	tempClock += _dt;
	SetPercentageDrawn(50 * (1 + sin(2 * PI * 0.5f * tempClock)), true);

	GetSprite()->setPosition(transform.m_Position);
}

void uiImage::SetPercentageDrawn(float _percentage, bool _fillFromLeft)
{
	// Boolean parameter indicates if bar should fill from the left or right

	float xSize = GetSprite()->getScale().x * GetTexture()->getSize().x;
	float ySize = GetSprite()->getScale().y * GetTexture()->getSize().y;

	int left = (_fillFromLeft) ? 0 : (int)(xSize * _percentage / 100.0f);
	int top = 0;
	int width = (int)(GetTexture()->getSize().x * _percentage / 100.0f);
	int height = (int)(GetSprite()->getScale().y * GetTexture()->getSize().y);

	GetSprite()->setTextureRect(sf::IntRect(
		left,
		0, 
		width,
		height));
}
