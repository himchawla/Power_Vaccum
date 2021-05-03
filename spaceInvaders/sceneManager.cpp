#include "sceneManager.h"
#include <iostream>

scene* sceneManager::m_CurrentScene = 0;
scene* sceneManager::m_SceneBuffer = 0;

void sceneManager::SetScene(scene* _scene)
{
	m_SceneBuffer = _scene;
}

void sceneManager::Update(sf::RenderWindow& _window)
{
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
