// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   sceneManager.cpp
//  Description :   Manages changing between scenes, starting and shutting down of game.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <iostream>
 // Local Includes 
 // This Include 
#include "sceneManager.h"
 // Static Variables 
scene* sceneManager::sm_CurrentScene = 0;
scene* sceneManager::sm_SceneBuffer = 0;
 // Static Function Prototypes 
 // Implementation 


/***********************
* SetScene: Puts scene in scene buffer.
* @author: William de Beer
* @parameter: New scene pointer.
********************/
void sceneManager::SetScene(scene* _scene)
{
	if (sm_SceneBuffer != nullptr)
	{
		delete sm_SceneBuffer;
		sm_SceneBuffer = 0;
		std::cout << "Overwriting scene buffer\n";
	}
	sm_SceneBuffer = _scene;
}

/***********************
* Update: Calls update function for current scene.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void sceneManager::Update(sf::RenderWindow& _window)
{
	// Ends when window is closed.
	while (_window.isOpen())
	{
		if (sm_SceneBuffer != nullptr)
		{
			if (sm_CurrentScene != nullptr)
			{
				delete sm_CurrentScene;
				sm_CurrentScene = 0;
			}
			sm_CurrentScene = sm_SceneBuffer;
			sm_CurrentScene->Initialise(_window);
			sm_SceneBuffer = nullptr;
		}

		if (sm_CurrentScene != nullptr)
		{
			sm_CurrentScene->MainLoop(_window);
		}
		else
		{
			std::cout << "No scene found! Send help!" << std::endl;
			_window.close();
		}
	}
}

/***********************
* Shutdown: Delete current scene, remove singletons.
* @author: William de Beer
********************/
void sceneManager::Shutdown()
{
	if (sm_CurrentScene != nullptr)
	{
		delete sm_CurrentScene;
		sm_CurrentScene = 0;
	}

	if (sm_SceneBuffer != nullptr)
	{
		delete sm_SceneBuffer;
		sm_SceneBuffer = 0;
	}

	scoreManager::RemoveInstance();
	audioManager::RemoveInstance();
}
