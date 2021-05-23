#ifndef __SCORE_MANAGER_H__
#define __SCORE_MANAGER_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   scoreManager.h
//  Description :   Contains and handles the scoring of the game.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <SFML/Graphics.hpp>
 // Local Includes 
#include "uiScore.h"
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 
class scoreManager
{
public:
	~scoreManager();

	static scoreManager& GetInstance();
	static void RemoveInstance();

	void Initialise();
	void IncrementScore(int _playerIndex);
	void DrawUI(sf::RenderWindow& _window);
	void Update(float _dT);
	int HighestScore();
	int WinningIndex();
	sf::Color WinningColor();
	void ResetScores();

	void GamePositioning();
	void EndPositioning();
private:
	scoreManager() {};
	static scoreManager* sm_Instance;

	uiScore* m_ScoreUI[4];
	int m_iPlayerScores[4];

	float m_xOffset = 150.0f;
	float m_yOffset = 100.0f;
};
#endif