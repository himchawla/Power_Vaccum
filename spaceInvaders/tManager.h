#ifndef __TMANAGER_H__
#define __TMANAGER_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   tManager.h
//  Description :   Tile Manager controller for all Tiles that will fall.
//  Author      :	Gervince Michael Go
//  Mail        :   Gervince.Go@mds.ac.nz 
// 
 // Library Includes 
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include <vector>
 // Local Includes 
#include "tile.h"
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

class tManager
{
public:
	tManager();
	bool isOnTile(sf::Vector2f _position, float _radius);
	virtual ~tManager();

	void Update(sf::RenderWindow& _window, float _dT);
	void DropTiles(float _dT);

	tile* GetTile(int _i);
	void AddTile(float _xPos, float _yPos);
	void RemoveTile(int _i);

	std::vector<tile*> GetTileVector();


	void Draw(sf::RenderWindow& _window);
private:

	std::vector<tile*> m_vTilesList;

	// Adjusting numbers, made variables to make it easier to track.
	sf::Vector2f m_v2FirstOffset = sf::Vector2f(300, 200);
	float m_fOffset = 75;
	int m_iVerticalTiles = 17;
	int m_iHorizontal = 8;
	int m_iTile = 0; // Tiles Selected to Fall
	int m_iTile1 = 0; // Tiles Selected to Fall
	int m_iTile2 = 0; // Tiles Selected to Fall

	// Independent Tile Manager Fall Timer
	float m_fFallTimer = 0.0f;
	float m_fTimeToFall = 5.5f; // Starting time to fall

	float m_fSpeedIncrease = 0.8f; // Increment increase time to fall;
	const float m_cfFallDefault = 5.5f; // Default Time to fal
	float m_fMaxFallTimer = 1.5f; // Minimum Time to Fall
	int m_iTimesFallen = 0; // How Many Tiles have fallen.


	// Shaking Animation.
	float m_fShakeTimer = 0.0f;
	float m_fShakeInterval = 0.1f;
	bool m_bLeft = false;
	int m_iInterval = 0;

	

	bool m_bFallAnimation = false;



};
#endif