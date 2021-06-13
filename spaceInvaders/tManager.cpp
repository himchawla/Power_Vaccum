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
#include <iostream>
 // Local Includes 
 // This Include 
#include "tManager.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 


tManager::tManager()
{
	int iTemp = rand() % 4 + 1;
	std::cout << iTemp << std::endl;

	switch (iTemp)
	{
		case  eFormShape::DEFAULT:
		{

			for (int i = 0; i < m_iVerticalTiles; i++) // Vertical
			{
				for (int j = 0; j < m_iHorizontal; j++) // Horizontal
				{
					m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (i * m_fOffset), m_v2FirstOffset.y + (j * m_fOffset)));
				}
			}
			break;
		}

		case  eFormShape::CIRCLE:
		{
			for (int i = 0; i < m_iHorizontal; i++)
			{
				if (i == 0 || i == 8)
				{
					for (int j = 0; j < m_iShortVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 4, m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
				else if (i == 1 || i == 2 || i == 6 || i == 7)
				{
					for (int j = 0; j < m_iMedVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 2, m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
				else
				{
					for (int j = 0; j < m_iHighVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset), m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
			}




			break;
		}

		case  eFormShape::STAR:
		{
			for (int i = 0; i < m_iHorizontal; i++)
			{
				if (i == 0 || i == 8)
				{
					for (int j = 0; j < m_iShortVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 4, m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
				else if (i == 1 || i == 2 || i == 6 || i == 7)
				{
					for (int j = 0; j < m_iMedVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 2, m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
				else
				{
					for (int j = 0; j < m_iHighVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset), m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
			}

			/*for (int i = 0; i < m_iHorizontal; i++)
			{
				if (i < 2)
				{

					for (int j = 0; j < m_iTopVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 6, m_v2FirstOffset.y + (i * m_fOffset)));
					}

				}
				else if (i == 2)
				{
					for (int j = 0; j < m_iConnectVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 4, m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
				else if (i == 3)
				{
					for (int j = 0; j < m_iPeakVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset), m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
				else if (i == 4)
				{
					for (int j = 0; j < m_iFallingActionVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 1, m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
				else if (i == 5 || i == 6)
				{
					if (i == 5)
					{
						for (int j = 0; j < m_iLegConnectVertical; j++)
						{
							m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 2, m_v2FirstOffset.y + (i * m_fOffset)));
						}
					}
					else
					{
						for (int j = 0; j < m_iLegConnectVertical - 2; j++)
						{
							m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 3, m_v2FirstOffset.y + (i * m_fOffset)));
						}
					}

					
				}
				else
				{
					for (int j = 0; j < m_iFeetVertical; j++)
					{

						if (i == 7)
						{
							if (j < 5)
							{
								m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 2, m_v2FirstOffset.y + (i * m_fOffset)));
							}
							else
							{
								m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 5, m_v2FirstOffset.y + (i * m_fOffset)));
							}
						}
						else
						{
							if (j < 5)
							{
								m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 1, m_v2FirstOffset.y + (i * m_fOffset)));
							}
							else
							{
								m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 7, m_v2FirstOffset.y + (i * m_fOffset)));
							}
						}

						

						
					}
				}
			}*/

			break;
		}

		case  eFormShape::BOAT:
		{
			for (int i = 0; i < m_iHorizontal; i++)
			{
				if (i == 0)
				{

					for (int j = 0; j < m_iCapVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 6, m_v2FirstOffset.y + (i * m_fOffset)));
					}

				}
				else if (i == 1)
				{
					for (int j = 0; j < m_iNestVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 2, m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
				else if (i >= 2 && i < 5)
				{
					for (int j = 0; j < m_iHullVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset), m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
				else if (i == 5)
				{
					for (int j = 0; j < m_iNestVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 1, m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
				else if (i == 6)
				{
					for (int j = 0; j < m_iSplitVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 1, m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
				else
				{
					for (int j = 0; j < m_iEdgeVertical; j++)
					{
						m_vTilesList.push_back(new tile(m_v2FirstOffset.x + (j * m_fOffset) + m_fOffset * 3, m_v2FirstOffset.y + (i * m_fOffset)));
					}
				}
			}

			break;
		}

		default:
		{
			// Do NOthing

			break;
		}
	}


	
}

bool tManager::isOnTile(sf::Vector2f _position, float _radius)
{
	for (auto i : m_vTilesList)
	{
		
		if ((i->GetPosition().x - 64.0f < _position.x && i->GetPosition().x + 64 > _position.x) && (i->GetPosition().y - 64.0f < _position.y && i->GetPosition().y + 64 > _position.y))
		{
			if(i->GetRect()->getSize().x > 0)
			return true;

		}
		else
			continue;
	}
	return false;
}

tManager::~tManager()
{
	std::vector<tile*>::iterator t_it = m_vTilesList.begin();
	while (t_it != m_vTilesList.end())
	{
		// Delete vector contents
		delete* t_it;
		t_it = m_vTilesList.erase((t_it));
	}
}

void tManager::Update(sf::RenderWindow& _window, float _dT)
{

	for (int i = 0; i < m_vTilesList.size(); i++)
	{
		m_vTilesList[i]->Update(_dT);
	}
	Draw(_window);
	DropTiles(_dT);
}

void tManager::DropTiles(float _dT)
{
	if (m_bFallAnimation != true)
	{
		m_fFallTimer += _dT;
	}
	

	if (m_fFallTimer >= m_fTimeToFall)
	{
		m_fFallTimer -= m_fTimeToFall;
		m_iTimesFallen++;
		m_fTimeToFall = m_cfFallDefault - (m_iTimesFallen * m_fSpeedIncrease);

		if (m_fTimeToFall < m_fMaxFallTimer)
		{
			m_fTimeToFall = m_fMaxFallTimer;
		}

		m_iTile = rand() % m_vTilesList.size();
		m_iTile1 = rand() % m_vTilesList.size();
		m_iTile2 = rand() % m_vTilesList.size();

		while (m_vTilesList[m_iTile]->GetRect()->getSize() == sf::Vector2f(0.0f, 0.0f) && 
			m_iTile1 != m_iTile && m_iTile != m_iTile2)
		{
			m_iTile = rand() % m_vTilesList.size();
		}

		while (m_vTilesList[m_iTile1]->GetRect()->getSize() == sf::Vector2f(0.0f, 0.0f) &&
			m_iTile1 != m_iTile && m_iTile1 != m_iTile2)
		{
			m_iTile1 = rand() % m_vTilesList.size();
		}

		while (m_vTilesList[m_iTile2]->GetRect()->getSize() == sf::Vector2f(0.0f, 0.0f) &&
			m_iTile1 != m_iTile2 && m_iTile != m_iTile2)
		{
			m_iTile2 = rand() % m_vTilesList.size();
		}

		m_vTilesList[m_iTile]->GetRect()->setFillColor(sf::Color::Red);
		m_vTilesList[m_iTile1]->GetRect()->setFillColor(sf::Color::Red);
		m_vTilesList[m_iTile2]->GetRect()->setFillColor(sf::Color::Red);
		m_bFallAnimation = true;


	}

	if (m_bFallAnimation == true)
	{
		m_fShakeTimer += _dT;
		if (m_fShakeTimer >= m_fShakeInterval)
		{
			m_fShakeTimer = 0;
			m_bLeft = !m_bLeft;
			m_iInterval++;
		}

		if (m_bLeft == true)
		{
			m_vTilesList[m_iTile]->GetRect()->move(-30.0f * _dT, 0.0f);
			m_vTilesList[m_iTile1]->GetRect()->move(-30.0f * _dT, 0.0f);
			m_vTilesList[m_iTile2]->GetRect()->move(-30.0f * _dT, 0.0f);
		}
		else
		{
			m_vTilesList[m_iTile]->GetRect()->move(30.0f * _dT, 0.0f);
			m_vTilesList[m_iTile1]->GetRect()->move(30.0f * _dT, 0.0f);
			m_vTilesList[m_iTile2]->GetRect()->move(30.0f * _dT, 0.0f);
		}

		if (m_iInterval >= 20)
		{
			m_bFallAnimation = false;
			m_bLeft = false;
			m_fShakeTimer = 0;
			m_iInterval = 0;
			RemoveTile(m_iTile);
			RemoveTile(m_iTile1);
			RemoveTile(m_iTile2);


		}
		
	}


	

}

tile* tManager::GetTile(int _i)
{
	return m_vTilesList[_i];
}

void tManager::AddTile(float _xPos, float _yPos)
{
	m_vTilesList.push_back(new tile(_xPos, _yPos));
}

void tManager::RemoveTile(int _i)
{	

	m_vTilesList[_i]->GetRect()->setSize(sf::Vector2f(0.0f, 0.0f));


}

std::vector<tile*> tManager::GetTileVector()
{
	return m_vTilesList;
}


void tManager::Draw(sf::RenderWindow& _window)
{
	for (int i = 0; i < m_vTilesList.size(); i++)
	{
		_window.draw(*m_vTilesList[i]->GetRect());

	}
}