// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   uiScore.cpp
//  Description :   Score display used to show users the current score.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
 // This Include 
#include "uiScore.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 
uiScore::uiScore(sf::Vector2f _pos, std::string _barTexLoc, std::string _pointTexLoc, sf::Color _color)
	: uiImage(_pos, _barTexLoc, false)
{
	m_iScore = 0;
	GetSprite()->setScale(0.5f, 0.5f);
	GetSprite()->setColor(_color);
	for (int i = 0; i < 3; i++)
	{
		// Create score background
		m_scorePoints[i] = new uiImage(sf::Vector2f(_pos.x - 64.0f + 64.0f * i, _pos.y), _pointTexLoc, false);
		m_scorePoints[i]->GetSprite()->setScale(GetSprite()->getScale() / 2.0f);
		m_scorePoints[i]->GetSprite()->setColor(_color);
	}
}

uiScore::~uiScore()
{
	for (int i = 0; i < 3; i++)
	{
		if (m_scorePoints[i] != nullptr)
		{
			delete m_scorePoints[i];
			m_scorePoints[i] = 0;
		}
	}
}

/***********************
* Update: Updates UI score.
* @author: William de Beer
* @parameter: Delta time
********************/
void uiScore::Update(float _dT)
{
	uiImage::Update(_dT);
	for (int i = 0; i < 3; i++)
	{
		m_scorePoints[i]->GetSprite()->setScale(GetSprite()->getScale() / 2.0f);
		m_scorePoints[i]->transform.m_Position = sf::Vector2f(transform.m_Position.x - 128.0f * GetSprite()->getScale().x + 128.0f * GetSprite()->getScale().x * i, transform.m_Position.y);
		m_scorePoints[i]->Update(_dT);
	}
}

/***********************
* Draw: Draws score bar and points.
* @author: William de Beer
* @parameter: Reference to render window
********************/
void uiScore::Draw(sf::RenderWindow& _window)
{
	gameObject::Draw(_window);
	for (int i = 0; i < 3; i++)
	{
		if (m_iScore > i)
		{
			m_scorePoints[i]->Draw(_window);
		}
	}
}

/***********************
* SetScore: Sets the score value.
* @author: William de Beer
* @parameter: Score integer
********************/
void uiScore::SetScore(int _score)
{
	m_iScore = _score;
}
