#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   gameScene.h
//  Description :   A class holds all relevant objects in the game world.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <vector>
 // Local Includes 
#include "scene.h"
#include "gameObject.h"
#include "tManager.h"
#include "Player.h"
#include "timer.h"

#include"battery.h"
#include "Text.h"

#include "uiImage.h"

 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 
class gameScene : public scene
{
public:
	
	gameScene(std::vector<player*>* _player, std::vector<int> _playerIndexes, int _numPlayers = 4);
	virtual ~gameScene();
	virtual void Initialise(sf::RenderWindow& _window);
	virtual void MainLoop(sf::RenderWindow& _window);
	virtual void SummonBattery();

private:
	virtual void Update(sf::RenderWindow& _window, float _dT);
	virtual void DrawBackground(sf::RenderWindow& _window);
	virtual void DrawObjects(sf::RenderWindow& _window);
	virtual void DrawUI(sf::RenderWindow& _window);
	virtual bool CheckFormation(int _Type);

	text* m_countdownText;
	std::vector<player*>* m_vPlayers;
	std::vector<gameObject*>* m_vObjects;
	sf::Texture* m_texBackground;
	sf::Sprite* m_sprBackground;
	tManager* m_tileManager;
	std::vector<battery*>* m_vBatteries;
	timer* m_startTimer;
	timer* m_batterySpawn;
	int m_numPlayers;
	std::vector<int> m_playerIndexes;
};
#endif
