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
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 
class gameScene : public scene
{
public:
	gameScene();
	~gameScene();
	virtual void Initialise(sf::RenderWindow& _window);
private:
	virtual void MainLoop(sf::RenderWindow& _window);
	virtual void Update(sf::RenderWindow& _window, float _dT);
	virtual void DrawBackground(sf::RenderWindow& _window);
	virtual void DrawObjects(sf::RenderWindow& _window);
	virtual void DrawUI(sf::RenderWindow& _window);

	std::vector<gameObject*>* m_vObjects;
};
#endif
