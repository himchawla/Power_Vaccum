// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   gameScene.cpp
//  Description :   A class holds all relevant objects in the game world.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
 // This Include 
#include "gameScene.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 
gameScene::gameScene()
{
	m_vObjects = new std::vector<gameObject*>();
	m_vPlayers = new std::vector<player*>();
	m_texBackground = new sf::Texture();
	m_sprBackground = new sf::Sprite();
}

gameScene::~gameScene()
{
	std::vector<player*>::iterator p_it = m_vPlayers->begin();
	while (p_it != m_vPlayers->end())
	{
		// Delete vector contents
		delete* p_it;
		p_it = m_vPlayers->erase((p_it));
	}
	if (m_vPlayers != nullptr) // Delete vector
	{
		delete m_vPlayers;
		m_vPlayers = 0;
	}

	std::vector<gameObject*>::iterator it = m_vObjects->begin();
	while (it != m_vObjects->end())
	{
		// Delete vector contents
		delete* it;
		it = m_vObjects->erase((it));
	}
	if (m_vObjects != nullptr) // Delete vector
	{
		delete m_vObjects;
		m_vObjects = 0;
	}

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
}

/***********************
* Initialise: Initialise scene and call MainLoop.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::Initialise(sf::RenderWindow& _window)
{
	// Create background
	m_texBackground->loadFromFile("Assets/BG.png");
	m_sprBackground->setTexture(*m_texBackground);
	m_sprBackground->setPosition(0, 0);

	MainLoop(_window);
}

/***********************
* MainLoop: Loop which calls update and render functions.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::MainLoop(sf::RenderWindow& _window)
{
	// Create all players
	for (int i = 0; i < 4; i++)
	{
		player* newPlayer = new player(i);
		newPlayer->transform.m_Position = (sf::Vector2f(100.0f * i, 100.0f));
		newPlayer->SetPlayerVector(m_vPlayers);
		m_vPlayers->push_back(newPlayer);
	}


	// Start clock
	sf::Clock clock;
	sf::Keyboard::Key key = sf::Keyboard::Escape;
	while (_window.isOpen())
	{
		sf::Event event;

		// Getting delta time
		float deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart(); 

		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window.close();
		}

		Update(_window, deltaTime);
		Render(_window);
	}
}

/***********************
* Update: Updates objects in the game scene.
* @author: William de Beer | Himanshu Chawla
* @parameter: Reference to render window, Delta time.
********************/
void gameScene::Update(sf::RenderWindow& _window, float _dT)
{
	// Update objects
	for (auto i : *m_vObjects)
	{
		i->Update(_dT);
	}

	// Update players
	for (auto i : *m_vPlayers)
	{
		i->Update(_dT);
	}
}

/***********************
* DrawBackground: Draws all background objects.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::DrawBackground(sf::RenderWindow& _window)
{
	// Draw background
	_window.draw(*m_sprBackground);
	//// Vector of background objects (if any) 
}

/***********************
* DrawObjects: Draws all objects that are not in the background or UI. This includes players, powerups and tiles.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::DrawObjects(sf::RenderWindow& _window)
{
	// Draw objects
	for (auto i : *m_vObjects)
	{
		if (i->GetSprite() != nullptr)
		{
			_window.draw(*(i)->GetSprite());
		}
	}

	// Draw players
	for (auto i : *m_vPlayers)
	{
		if (i->GetSprite() != nullptr)
		{
			_window.draw(*(i)->GetSprite());
		}
	}

	tileManager->Draw(_window);
}

/***********************
* DrawUI: Draws all UI elements.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::DrawUI(sf::RenderWindow& _window)
{
	// Draw UI elements
}
