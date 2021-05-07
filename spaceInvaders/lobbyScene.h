#ifndef __LOBBY_SCENE_H__
#define __LOBBY_SCENE_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   lobbyScene.h
//  Description :   A lobby scene where players tag in and out of the game before playing.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
#include "scene.h"
#include "uiImage.h"
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

class lobbyScene : public scene
{
public:
	lobbyScene();
	virtual ~lobbyScene();
	virtual void Initialise(sf::RenderWindow& _window);
	virtual void MainLoop(sf::RenderWindow& _window);
private:
	virtual void Update(sf::RenderWindow& _window, float _dT);
	virtual void DrawBackground(sf::RenderWindow& _window);
	virtual void DrawObjects(sf::RenderWindow& _window);
	virtual void DrawUI(sf::RenderWindow& _window);

	bool m_hasJoined[4];
	int m_numPlayers = 0;
	bool m_canStart;
	sf::Texture* m_texBackground;
	sf::Sprite* m_sprBackground;

	std::vector<player*>* m_vPlayers;


	uiImage* temp1;
	uiImage* temp2;
};
#endif