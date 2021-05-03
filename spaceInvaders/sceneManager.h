#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   sceneManager.h
//  Description :   Manages changing between scenes, starting and shutting down of game.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
#include "scene.h"
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 
class sceneManager
{
public:
	static void SetScene(scene* _scene);
	static void Update(sf::RenderWindow& _window);
	static void Shutdown();

private:
	static scene* m_CurrentScene;
	static scene* m_SceneBuffer;
};

#endif