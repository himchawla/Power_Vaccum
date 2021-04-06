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
	virtual ~tManager();

	void Update(sf::RenderWindow& _window, float _dT);

	tile* GetTile(int _i);
	void AddTile(tile* _tile);
	void RemoveTile(int _i);

	void Draw(sf::RenderWindow& _window);
private:
	struct Tiles
	{
		sf::Vector2f m_Position;
		sf::Vector2f m_size;
		sf::RectangleShape m_TempRect;
		sf::Sprite* m_Sprite;
	};

	// Trying 2 ways to do this.
	//std::vector<tile*> TilesList;
	std::vector<tile*> m_vTilesList;


};
#endif
