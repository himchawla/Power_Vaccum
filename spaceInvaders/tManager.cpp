// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   tManager.h
//  Description :   [WIP] Tile Manager controller for all Tiles that will fall.
//  Author      :   Gervince Michael Go
//  Mail        :   Gervince.Go@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
 // This Include 
#include "tManager.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 


tManager::tManager()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m_vTilesList.push_back(new tile);
		}
	}
}

tManager::~tManager()
{
}

void tManager::Update(sf::RenderWindow& _window, float _dT)
{
	Draw(_window);
}

tile* tManager::GetTile(int _i)
{
	return m_vTilesList[_i];
}

void tManager::AddTile(tile* _tile)
{
	m_vTilesList.push_back(_tile);
}

void tManager::RemoveTile(int _i)
{
	


}

void tManager::Draw(sf::RenderWindow& _window)
{
	for (int i = 0; i < m_vTilesList.size(); i++)
	{
		_window.draw(*m_vTilesList[i]->GetRect());

	}
}