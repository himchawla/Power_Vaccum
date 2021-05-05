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
scene* sceneManager::m_CurrentScene = 0;
scene* sceneManager::m_SceneBuffer = 0;
 // Static Function Prototypes 
 // Implementation 


/***********************
* SetScene: Puts scene in scene buffer.
* @author: William de Beer
* @parameter: New scene pointer.
********************/
void sceneManager::SetScene(scene* _scene)
{
	m_SceneBuffer = _scene;
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
		if (m_SceneBuffer != nullptr)
		{
			if (m_CurrentScene != nullptr)
			{
				delete m_CurrentScene;
				m_CurrentScene = 0;
			}
			m_CurrentScene = m_SceneBuffer;
			m_CurrentScene->Initialise(_window);
			m_SceneBuffer = nullptr;
		}

		if (m_CurrentScene != nullptr)
		{
			m_CurrentScene->MainLoop(_window);
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
	if (m_CurrentScene != nullptr)
	{
		delete m_CurrentScene;
		m_CurrentScene = 0;
	}

	if (m_SceneBuffer != nullptr)
	{
		delete m_SceneBuffer;
		m_SceneBuffer = 0;
	}
}
