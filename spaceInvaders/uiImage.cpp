// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   uiImage.cpp
//  Description :   Class used to display images and resources
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
#include "uiImage.h"
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 
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

/***********************
* Update: Updates image object.
* @author: William de Beer
* @parameter: Delta time.
********************/
void uiImage::Update(float _dt)
{
	// Demonstrates the bar functionality
	tempClock += _dt;
	SetPercentageDrawn(50 * (1 + sin(2 * PI * 0.5f * tempClock)));

	GetSprite()->setPosition(transform.m_Position);
}

/***********************
* SetPercentageDrawn: Sets the percentage of the sprite which is to be drawn.
* @author: William de Beer
* @parameter: Percentage float. Should be <100 and >=0
********************/
void uiImage::SetPercentageDrawn(float _percentage)
{
	// Gets texture size
	float xSize = (GetTexture()->getSize().x);
	float ySize = (GetTexture()->getSize().y);

	int left = 0;
	int top = 0;
	int width = (int)(xSize * _percentage / 100.0f);
	int height = (int)(ySize);

	GetSprite()->setTextureRect(sf::IntRect(
		left,
		top,
		width,
		height));
}
