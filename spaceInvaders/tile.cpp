// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   gameObject.h
//  Description :   Tile Manager controller for all Tiles that will fall.
//  Author      :   Gervince Michael Go
//  Mail        :   Gervince.Go@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
 // This Include 
#include "tile.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 




tile::tile(float x_pos, float y_pos)
{
	m_TempRect = new sf::RectangleShape;

	m_TempRect->setSize(sf::Vector2f(m_v2TileSize));
	m_TempRect->setFillColor(sf::Color::White);
	m_TempRect->setOutlineThickness(2);
	m_TempRect->setOutlineColor(sf::Color::Black);
	m_TempRect->setPosition(x_pos, y_pos);
	m_TempRect->setOrigin(m_v2TileSize.x * 0.5f, m_v2TileSize.y * 0.5f);
	
}

tile::~tile()
{

}


void tile::Update(float _dT)
{
	m_TempRect->getPosition().x;
}

sf::Vector2f tile::GetPosition()
{
	return m_TempRect->getPosition();
}


void tile::SetPosition(sf::Vector2f _position)
{

}


sf::RectangleShape* tile::GetRect()
{
	return m_TempRect;
}

void tile::SetRect(sf::RectangleShape* _rect)
{
	m_TempRect = _rect;
}

