// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   lobbyScene.cpp
//  Description :   A lobby scene where players tag in and out of the game before playing.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include<iostream>
 // Local Includes 
#include "gameScene.h"
#include "sceneManager.h"
 // This Include 
#include "lobbyScene.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

lobbyScene::lobbyScene()
{
	m_texBackground = new sf::Texture();
	m_sprBackground = new sf::Sprite();

	for (int i = 0; i < 4; i++)
	{
		m_playerStatus[i].SetSpriteFromFile("Assets/Ready.png");
		m_playerStatus[i].GetSprite()->setScale(sf::Vector2f(0.5f, 0.5f));
	}

	m_playerStatus[0].transform.m_Position.x = 560.0f;
	m_playerStatus[0].transform.m_Position.y = 275.0f;
	m_playerStatus[1].transform.m_Position.x = 1715.0f;
	m_playerStatus[1].transform.m_Position.y = 275.0f;


	m_playerStatus[2].transform.m_Position.x = 560.0f;
	m_playerStatus[2].transform.m_Position.y = 797.0f;
	m_playerStatus[3].transform.m_Position.x = 1715.0f;
	m_playerStatus[3].transform.m_Position.y = 797.0f;

	

	m_vPlayers = new std::vector<player*>();

	temp1 = new uiImage(sf::Vector2f(100, 100), "Assets/TempBar.png", true);
	temp2 = new uiImage(sf::Vector2f(800, 100), "Assets/TempBar.png", true);
}

lobbyScene::~lobbyScene()
{
	// Delete background 
	if (m_texBackground != nullptr)
	{
		delete m_texBackground;
		m_texBackground = 0;
	}
	if (m_sprBackground != nullptr)
	{
		delete m_sprBackground;
		m_sprBackground = 0;
	}

	// temp
	if (temp1 != nullptr)
	{
		delete temp1;
		temp1 = 0;
	}
}

/***********************
* Initialise: Initialise scene.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void lobbyScene::Initialise(sf::RenderWindow& _window)
{
	// Create background
	m_texBackground->loadFromFile("Assets/lobby.png");
	m_sprBackground->setTexture(*m_texBackground);
	m_sprBackground->setPosition(0, 0);

	// Set up demo images
	temp1->GetSprite()->setColor(sf::Color::Red);
	temp1->GetSprite()->setScale(sf::Vector2f(4.0f, 4.0f));

	temp2->GetSprite()->setColor(sf::Color::Blue);
	temp2->GetSprite()->setScale(sf::Vector2f(-4.0f, 4.0f));
}

/***********************
* MainLoop: Loop which calls update and render functions.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void lobbyScene::MainLoop(sf::RenderWindow& _window)
{
	sf::Event event;

	// Getting delta time
	float deltaTime = m_Clock.getElapsedTime().asSeconds();
	m_Clock.restart();

	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window.close();
	}

	Update(_window, deltaTime);
	Render(_window);
}


/***********************
* Update: Updates objects in the game scene.
* @author: William de Beer
* @parameter: Reference to render window, Delta time.
********************/
void lobbyScene::Update(sf::RenderWindow& _window, float _dT)
{
	temp1->Update(_dT);
	temp2->Update(_dT);



	for (int i = 0; i < 4; i++)
	{
		m_playerStatus[i].Update(_dT);
		if (inputManager::GetControllerButton(3, i) && !m_hasJoined[i])
		{
			m_numPlayers++;
			if (m_numPlayers > 1 && !m_canStart)
			{
				m_canStart = true;
			}
			m_hasJoined[i] = true;
			std::cout << "Player " << i << " has joined the game";
			player* newPlayer = new player(i);

			m_playerStatus[m_numPlayers - 1].SetSpriteFromFile("Assets/Ready_NO.png");
			m_playerStatus[m_numPlayers - 1].GetSprite()->setScale(sf::Vector2f(0.5f, 0.5f));

			switch (m_numPlayers)
			{
			case 1:
				newPlayer->transform.m_Position = (sf::Vector2f(320.0f, 275.0f));
				break;
			case 2:
				newPlayer->transform.m_Position = (sf::Vector2f(1475.0f, 275.0f));
				break;
			case 3:
				newPlayer->transform.m_Position = (sf::Vector2f(320.0f, 797.0f));
				break;
			case 4:
				newPlayer->transform.m_Position = (sf::Vector2f(1475.0f, 797.0f));
				break;
			default:
				break;
			}
			
			reinterpret_cast<gameObject*>(newPlayer)->Update(_dT);

			newPlayer->SetPlayerVector(m_vPlayers);
			m_vPlayers->push_back(newPlayer);
		}


	}
	// Start game
	
	for (auto i : *m_vPlayers)
	{
		i->Update(_dT);
	}

	int k = 0;
	for (auto i : *m_vPlayers)
	{

		if (!i->IsReady())
		{
			m_canStart = false;
			break;
		}
		else 
		{
			m_canStart = true;
		}
		k++;
	}

	k = 0;
	for (auto i : *m_vPlayers)
	{

		if (!i->IsReady())
		{
			m_playerStatus[k].SetSpriteFromFile("Assets/Ready_NO.png");
			m_playerStatus[k].GetSprite()->setScale(sf::Vector2f(0.5f, 0.5f));
		}
		else
		{
			m_playerStatus[k].SetSpriteFromFile("Assets/Ready_YES.png");
			m_playerStatus[k].GetSprite()->setScale(sf::Vector2f(0.5f, 0.5f));
		}
		k++;
	}

	if (m_canStart && m_numPlayers > 1)
	{
		sceneManager::SetScene(new gameScene(m_vPlayers));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		sceneManager::SetScene(new gameScene(nullptr));
	}

	
		
}

/***********************
* DrawBackground: Draws all background objects.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void lobbyScene::DrawBackground(sf::RenderWindow& _window)
{
	// Draw background
	_window.draw(*m_sprBackground);
}

/***********************
* DrawObjects: Draws all objects that are not in the background or UI.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void lobbyScene::DrawObjects(sf::RenderWindow& _window)
{
	for (auto i : *m_vPlayers)
	{
		i->Draw(_window);
	}

	for (int i = 0; i < 4; i++)
	{
		m_playerStatus[i].Draw(_window);
	}
}

/***********************
* DrawUI: Draws all UI elements.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void lobbyScene::DrawUI(sf::RenderWindow& _window)
{
	// Draw UI elements
	_window.draw(*temp1->GetSprite());
	_window.draw(*temp2->GetSprite());
}
