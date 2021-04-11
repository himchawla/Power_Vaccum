#pragma once
#ifndef __TILE_H__
#define __TILE_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   tile.h
//  Description :   Individual Tiles on the field.
//  Author      :   Gervince Michael Go
//  Mail        :   Gervince.Go@mds.ac.nz
// 
 // Library Includes 
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
 // Local Includes 
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

class tile
{
public:
	tile();
	tile(float x_pos, float y_pos);
	virtual ~tile();

	void Update(float _dT);

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f _position);

	sf::RectangleShape* GetRect();
	void SetRect(sf::RectangleShape* _rect);
private:
	sf::RectangleShape* m_TempRect;
	sf::Vector2f m_2fPosition;
	float m_fRotation;
};
#endif