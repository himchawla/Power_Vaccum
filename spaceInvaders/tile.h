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
#include "gameObject.h"
#include "battery.h"
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

class tile : public gameObject
{
public:
	
	tile(float x_pos, float y_pos);
	virtual ~tile();

	//void SetPlayerVector(std::vector<player*>* _player);
	
	void Update(float _dT);

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f _position);

	sf::RectangleShape* GetRect();
	void SetRect(sf::RectangleShape* _rect);
    bool PixelPerfectTest(const sf::Sprite& Object1, const sf::Sprite& Object2, sf::Uint8 AlphaLimit);

	void SetBattery(battery* _battery);
	battery* GetBattery() { return m_connectedBattery; };

private:
	//std::vector<player*>* m_vPlayers;
	sf::RectangleShape* m_TempRect;
	sf::Vector2f m_2fPosition;
	float m_fRotation;
	int m_iWeight = 0;
	battery* m_connectedBattery;
	sf::Vector2f m_v2TileSize = sf::Vector2f(70, 70);
};
#endif
