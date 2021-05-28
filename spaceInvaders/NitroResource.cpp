// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   scoreManager.cpp
//  Description :   Contains and handles the scoring of the game.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <iostream>
 // Local Includes 
 // This Include 
#include "NitroResource.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

scoreManager* scoreManager::sm_Instance = 0;

scoreManager::~scoreManager()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_NitroUI[i] != nullptr)
		{
			delete m_NitroUI[i];
			m_NitroUI[i] = 0;
		}
	}
}

/***********************
* GetInstance: Returns instance of scoreManager.
* @author: William de Beer
* @return: scoreManager instance
********************/
scoreManager& scoreManager::GetInstance()
{
	if (sm_Instance == 0)
	{
		sm_Instance = new scoreManager();
		sm_Instance->Initialise();
	}
	return *sm_Instance;
}

/***********************
* RemoveInstance: Deletes current instance of scoreManager.
* @author: William de Beer
********************/
void scoreManager::RemoveInstance()
{
	if (sm_Instance != 0)
	{
		delete sm_Instance;
		sm_Instance = 0;
	}
}

/***********************
* Initialise: Initialises instance of scoreManager.
* @author: William de Beer
********************/
void scoreManager::Initialise()
{
	m_NitroUI[0] = new uiScore(sf::Vector2f(m_xOffset, m_yOffset), "Assets/ScoreBar.png", "Assets/ScorePoint.png", sf::Color::Red);
	m_NitroUI[1] = new uiScore(sf::Vector2f(1920 - m_xOffset, m_yOffset), "Assets/ScoreBar.png", "Assets/ScorePoint.png", sf::Color::Cyan);
	m_NitroUI[2] = new uiScore(sf::Vector2f(m_xOffset, 1080 - m_yOffset), "Assets/ScoreBar.png", "Assets/ScorePoint.png", sf::Color::Green);
	m_NitroUI[3] = new uiScore(sf::Vector2f(1920 - m_xOffset, 1080 - m_yOffset), "Assets/ScoreBar.png", "Assets/ScorePoint.png", sf::Color::Yellow);

	for (int i = 0; i < 4; i++)
	{
		m_iPlayerScores[i] = 2;
		m_NitroUI[i]->SetScore(m_iPlayerScores[i]);
	}
}


/***********************
* Draw: Calls draw functions for all score UI.
* @author: William de Beer
* @parameter: Reference to render window
********************/
void scoreManager::DrawUI(sf::RenderWindow& _window)
{
	for (int i = 0; i < 4; i++)
	{
		m_NitroUI[i]->Draw(_window);
	}
}

void scoreManager::Update(float _dT)
{
	for (int i = 0; i < 4; i++)
	{
		m_NitroUI[i]->Update(_dT);
	}
}

void scoreManager::GamePositioning()
{
	for (int i = 0; i < 4; i++)
	{
		m_NitroUI[i]->GetSprite()->setScale(sf::Vector2f(0.5f, 0.5f));
	}

	m_NitroUI[0]->transform.m_Position = sf::Vector2f(m_xOffset, m_yOffset);
	m_NitroUI[1]->transform.m_Position = sf::Vector2f(1920 - m_xOffset, m_yOffset);
	m_NitroUI[2]->transform.m_Position = sf::Vector2f(m_xOffset, 1080 - m_yOffset);
	m_NitroUI[3]->transform.m_Position = sf::Vector2f(1920 - m_xOffset, 1080 - m_yOffset);
}