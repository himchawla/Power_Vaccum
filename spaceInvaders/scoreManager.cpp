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
#include "scoreManager.h"
 // Static Variables 
scoreManager* scoreManager::sm_Instance = 0;
 // Static Function Prototypes 
 // Implementation 


scoreManager::~scoreManager()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_ScoreUI[i] != nullptr)
		{
			delete m_ScoreUI[i];
			m_ScoreUI[i] = 0;
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
	m_ScoreUI[0] = new uiScore(sf::Vector2f(m_xOffset, m_yOffset) , "Assets/ScoreBar.png", "Assets/ScorePoint.png", sf::Color::Red);
	m_ScoreUI[1] = new uiScore(sf::Vector2f(1920 - m_xOffset, m_yOffset), "Assets/ScoreBar.png", "Assets/ScorePoint.png", sf::Color::Cyan);
	m_ScoreUI[2] = new uiScore(sf::Vector2f(m_xOffset, 1080 - m_yOffset) , "Assets/ScoreBar.png", "Assets/ScorePoint.png", sf::Color::Green);
	m_ScoreUI[3] = new uiScore(sf::Vector2f(1920 - m_xOffset, 1080 - m_yOffset), "Assets/ScoreBar.png", "Assets/ScorePoint.png", sf::Color::Yellow);

	for (int i = 0; i < 4; i++)
	{
		m_iPlayerScores[i] = 0;
		m_ScoreUI[i]->SetScore(m_iPlayerScores[i]);
	}
}

/***********************
* IncrementScore: Increments the score of the chosen index.
* @author: William de Beer
* @parameter: Player index
********************/
void scoreManager::IncrementScore(int _playerIndex)
{
	if (_playerIndex >= 0 && _playerIndex < 4)
	{
		m_iPlayerScores[_playerIndex]++;
		m_ScoreUI[_playerIndex]->SetScore(m_iPlayerScores[_playerIndex]);
		m_lastVictor = _playerIndex;
	}
	else
	{
		std::cout << "Invalid player index used in scoreManager::IncrementScore" << std::endl;
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
		m_ScoreUI[i]->Draw(_window);
	}
}

void scoreManager::Update(float _dT)
{
	for (int i = 0; i < 4; i++)
	{
		m_ScoreUI[i]->Update(_dT);
	}
}

/***********************
* HighestScore: Returns the highest score in the game.
* @author: William de Beer
* @return: Integer score
********************/
int scoreManager::HighestScore()
{
	int highestScore = 0;
	for (int i = 0; i < 4; i ++)
	{
		if (m_iPlayerScores[i] > highestScore)
			highestScore = m_iPlayerScores[i];
	}
	return highestScore;
}

/***********************
* WinningIndex: Returns the highest scoring player's index.
* @author: William de Beer
* @return: Player index
********************/
int scoreManager::WinningIndex()
{
	int winningIndex = 0;
	for (int i = 0; i < 4; i++)
	{
		if (m_iPlayerScores[i] > m_iPlayerScores[winningIndex])
			winningIndex = i;
	}
	bool flag = false;
	for(auto it:m_iPlayerScores)
	{
		if (it > 0)
		{
			flag = true;
			break;
		}
	}
	if (flag)
		return winningIndex;
	else
		return -1;
}

sf::Color scoreManager::WinningColor()
{
	if(WinningIndex() >= 0)
		return m_ScoreUI[WinningIndex()]->GetSprite()->getColor();
	return sf::Color::Black;
}

/***********************
* ResetScores: Resets the score of all players.
* @author: William de Beer
* @parameter: Parameters
* @return: Return values
********************/
void scoreManager::ResetScores()
{
	for (int i = 0; i < 4; i++)
	{
		m_iPlayerScores[i] = 0;
		m_ScoreUI[i]->SetScore(m_iPlayerScores[i]);
	}
}

void scoreManager::GamePositioning()
{
	for (int i = 0; i < 4; i++)
	{
		m_ScoreUI[i]->GetSprite()->setScale(sf::Vector2f(0.5f, 0.5f));
	}

	m_ScoreUI[0]->transform.m_Position = sf::Vector2f(m_xOffset, m_yOffset);
	m_ScoreUI[1]->transform.m_Position = sf::Vector2f(1920 - m_xOffset, m_yOffset);
	m_ScoreUI[2]->transform.m_Position = sf::Vector2f(m_xOffset, 1080 - m_yOffset);
	m_ScoreUI[3]->transform.m_Position = sf::Vector2f(1920 - m_xOffset, 1080 - m_yOffset);
}

void scoreManager::EndPositioning()
{
	for (int i = 0; i < 4; i++)
	{
		m_ScoreUI[i]->GetSprite()->setScale(sf::Vector2f(1.0f, 1.0f));
	}
	m_ScoreUI[WinningIndex()]->GetSprite()->setScale(sf::Vector2f(1.1f, 1.1f));

	m_ScoreUI[0]->transform.m_Position = sf::Vector2f(960, 500);
	m_ScoreUI[1]->transform.m_Position = sf::Vector2f(960, 580);
	m_ScoreUI[2]->transform.m_Position = sf::Vector2f(960, 660);
	m_ScoreUI[3]->transform.m_Position = sf::Vector2f(960, 740);
}
