#ifndef __END_SCENE_H__
#define __END_SCENE_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   endScene.h
//  Description :   A end scene which will display who won the match.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
#include "scene.h"
#include "uiImage.h"
#include "Player.h"
#include "timer.h"
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

class endScene : public scene
{
public:
	endScene();
	virtual ~endScene();
	virtual void Initialise(sf::RenderWindow& _window);
	virtual void MainLoop(sf::RenderWindow& _window);
private:
	virtual void Update(sf::RenderWindow& _window, float _dT);
	virtual void DrawBackground(sf::RenderWindow& _window);
	virtual void DrawObjects(sf::RenderWindow& _window);
	virtual void DrawUI(sf::RenderWindow& _window);

	sf::Texture* m_texBackground;
	sf::Sprite* m_sprBackground;
	sf::Text m_txtWinner;
	sf::Font m_fntWinner;
	timer* m_leaveTimer;
};
#endif