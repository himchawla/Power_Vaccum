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
#include "sceneManager.h"
 // This Include 
#include "gameScene.h"

 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

bool isDebug = false;

gameScene::gameScene(std::vector<player*>* _player)
{
	m_vObjects = new std::vector<gameObject*>();
	
	m_tileManager = new tManager();
	m_vPlayers = _player;
	if (m_vPlayers == nullptr)
	{
		m_vPlayers = new std::vector<player*>();

		for (int i = 0; i < 4; i++)
		{
			player* newPlayer = new player(i);

			switch (m_vPlayers->size())
			{
			case 0:
				newPlayer->transform.m_Position = (sf::Vector2f(320.0f, 275.0f));
				break;
			case 1:
				newPlayer->transform.m_Position = (sf::Vector2f(1475.0f, 275.0f));
				break;
			case 2:
				newPlayer->transform.m_Position = (sf::Vector2f(320.0f, 697.0f));
				break;
			case 3:
				newPlayer->transform.m_Position = (sf::Vector2f(1475.0f, 697.0f));
			}
			newPlayer->SetPlayerVector(m_vPlayers);
			newPlayer->SetTileManager(m_tileManager);
			m_vPlayers->push_back(newPlayer);

		}
	}
	else
	{
		int numPlayers = 1;
		for (auto p_it : *m_vPlayers)
		{
			switch (numPlayers)
			{
			case 1:
				p_it->transform.m_Position = (sf::Vector2f(320.0f, 275.0f));
				break;
			case 2:
				p_it->transform.m_Position = (sf::Vector2f(1475.0f, 275.0f));
				break;
			case 3:
				p_it->transform.m_Position = (sf::Vector2f(320.0f, 697.0f));
				break;
			case 4:
				p_it->transform.m_Position = (sf::Vector2f(1475.0f, 697.0f));
			}
			numPlayers++;
			p_it->SetTileManager(m_tileManager);
			p_it->SetBatteryVector(m_vBatteries);
		}
	
	}
	m_texBackground = new sf::Texture();
	m_sprBackground = new sf::Sprite();
	m_vBatteries = new std::vector<battery*>();
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

	delete m_tileManager;
	m_tileManager = 0;

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
* Initialise: Initialise scene.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::Initialise(sf::RenderWindow& _window)
{
	// Create background
	m_texBackground->loadFromFile("Assets/BG.png");
	m_sprBackground->setTexture(*m_texBackground);
	m_sprBackground->setPosition(0, 0);

	battery* bat = new battery(3, sf::Vector2f(500.0f, 200.0f));
	//bat->transform.m_Position = sf::Vector2f(100.0f, 400.0f);
	m_vBatteries->push_back(bat);

	bat = new battery(2, sf::Vector2f(200.0f, 800.0f));
	m_vBatteries->push_back(bat);




	scoreManager::GetInstance().ResetScores();
	scoreManager::GetInstance().GamePositioning();
}

/***********************
* MainLoop: Loop which calls update and render functions.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::MainLoop(sf::RenderWindow& _window)
{
	sf::Event event;

	// Getting delta time
	float deltaTime = m_Clock.getElapsedTime().asSeconds();
	m_Clock.restart();

	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window.close();

		//Just to check the death function/ Delete Later
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::V)
		{
			for (auto p_it : *m_vPlayers)
			{
				p_it->death();
				break;
			}
		}
	}

	Update(_window, deltaTime);
	Render(_window);
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
	if (m_vPlayers->size() == 1)
	{
		//Load End Scene Here
		sceneManager::SetScene(new gameScene(nullptr));
	}

	for (auto i : *m_vBatteries)
	{
		i->Update(_dT);
	}

	scoreManager::GetInstance().Update(_dT);
	m_tileManager->Update(_window, _dT);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		sceneManager::SetScene(new gameScene(nullptr));
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
	for (auto it : *m_vObjects)
	{
		it->Draw(_window);
	}

	m_tileManager->Draw(_window);
	// Draw circle indicators
	for (auto p_it : *m_vPlayers)
	{
		p_it->DrawCircleIndicator(_window);
	}

	// Draw players
	for (auto p_it : *m_vPlayers)
	{
		p_it->Draw(_window);
		
	}

	for (auto b_it : *m_vBatteries)
	{
		b_it->Draw(_window);
	}

	
}

/***********************
* DrawUI: Draws all UI elements.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::DrawUI(sf::RenderWindow& _window)
{
	scoreManager::GetInstance().DrawUI(_window);
}
