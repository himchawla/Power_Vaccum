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


tManager::tManager(std::vector<player*>* m_vPlayers)
{
	for (int i = 0; i < m_iVerticalTiles; i++) // Vertical
	{
		for (int j = 0; j < m_iHorizontal; j++) // Horizontal
		{

			m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (i * m_fOffset), m_v2FirstOffset.y + (j * m_fOffset), m_vPlayers));

			

		}
	}
}

tManager::~tManager()
{
}

void tManager::Update(sf::RenderWindow& _window, float _dT)
{
	Draw(_window);
	DropTiles(_dT);
}

void tManager::DropTiles(float _dT)
{
	m_fFallTimer += _dT;

	if (m_fFallTimer >= m_fTimeToFall)
	{
		// Exponentially get faster :)
		m_fFallTimer -= m_fTimeToFall;
		int iTemp = rand() % 136;

		while (m_vTilesList[iTemp]->GetRect()->getSize() == sf::Vector2f(0.0f, 0.0f))
		{
			iTemp = rand() % 136;
		}


		RemoveTile(iTemp);


	}
}

tile* tManager::GetTile(int _i)
{
	return m_vTilesList[_i];
}

void tManager::AddTile(float _xPos, float _yPos)
{
	m_vTilesList.push_back(new tile(_xPos, _yPos, nullptr));
}

void tManager::RemoveTile(int _i)
{	
	// Do Nothing for now.
	m_vTilesList[_i]->GetRect()->setSize(sf::Vector2f(0.0f, 0.0f));


}

void tManager::Draw(sf::RenderWindow& _window)
{
	for (int i = 0; i < m_vTilesList.size(); i++)
	{
		_window.draw(*m_vTilesList[i]->GetRect());

	}
}