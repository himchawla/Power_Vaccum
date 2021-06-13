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
#include "endScene.h"
 // This Include 
#include "gameScene.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

bool isDebug = false;

gameScene::gameScene(std::vector<player*>* _player, int _numPlayers)
{
	m_vObjects = new std::vector<gameObject*>();
	m_vBatteries = new std::vector<battery*>();
	m_tileManager = new tManager();
	m_vPlayers = _player;
	m_batterySpawn = 0;
	m_startTimer = new timer(3, 0);

	m_countdownText = new text(sf::Vector2<float>(960.0f, 520.0f));
	
	if (m_vPlayers == nullptr)
	{
		m_numPlayers = _numPlayers;

		
		m_vPlayers = new std::vector<player*>();

		for (int i = 0; i < _numPlayers; i++)
		{
			player* newPlayer = new player(i);

			switch (m_vPlayers->size())
			{
			case 0:
				newPlayer->transform.m_Position = (sf::Vector2f(420.0f, 375.0f));
				break;
			case 1:
				newPlayer->transform.m_Position = (sf::Vector2f(1375.0f, 375.0f));
				break;
			case 2:
				newPlayer->transform.m_Position = (sf::Vector2f(420.0f, 597.0f));
				break;
			case 3:
				newPlayer->transform.m_Position = (sf::Vector2f(1375.0f, 597.0f));
			}
			newPlayer->SetPlayerVector(m_vPlayers);
			newPlayer->SetBatteryVector(m_vBatteries);
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
				p_it->transform.m_Position = (sf::Vector2f(420.0f, 375.0f));
				break;
			case 2:
				p_it->transform.m_Position = (sf::Vector2f(1375.0f, 375.0f));
				break;
			case 3:
				p_it->transform.m_Position = (sf::Vector2f(420.0f, 597.0f));
				break;
			case 4:
				p_it->transform.m_Position = (sf::Vector2f(1375.0f, 597.0f));
			}
			numPlayers++;
			p_it->SetTileManager(m_tileManager);
			p_it->SetBatteryVector(m_vBatteries);
		}
		m_numPlayers = numPlayers - 1;

	
	}

	// Initialise update to ensure players a place correctly.
	for (auto i : *m_vPlayers)
	{
		i->Update(0);
	}

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

	if (m_tileManager != nullptr) // Delete tile manager
	{
		delete m_tileManager;
		m_tileManager = 0;
	}

	if(m_countdownText!= nullptr)
	{
		delete m_countdownText;
		m_countdownText = nullptr;
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

	std::vector<battery*>::iterator b_it = m_vBatteries->begin();
	while (b_it != m_vBatteries->end())
	{
		// Delete vector contents
		delete* b_it;
		b_it = m_vBatteries->erase((b_it));
	}
	if (m_vBatteries != nullptr) // Delete vector
	{
		delete m_vBatteries;
		m_vBatteries = 0;
	}

	if (m_batterySpawn != nullptr)
	{
		delete m_batterySpawn;
		m_batterySpawn = 0;
	}
	if (m_startTimer != nullptr)
	{
		delete m_startTimer;
		m_startTimer = 0;
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

	m_batterySpawn = new timer(0.0f, 5.0f);
	
	//battery* bat = new battery(3, sf::Vector2f(500.0f, 200.0f));
	//bat->transform.m_Position = sf::Vector2f(100.0f, 400.0f);
	//m_vBatteries->push_back(bat);

	//bat = new battery(2, sf::Vector2f(200.0f, 800.0f));
	//m_vBatteries->push_back(bat);


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

	if (m_startTimer != nullptr) // Start delay timer.
	{
		m_startTimer->Update(_dT);
		if (m_countdownText != nullptr)	m_countdownText->SetString((std::to_string((int)m_startTimer->GetTime())));
		if (m_startTimer->IsFinished())
		{
			delete m_startTimer;
			m_startTimer = 0;
		}
	}
	else
	{
		// Update players
		for (auto i : *m_vPlayers)
		{
			i->Update(_dT);
		}
		if (m_vPlayers->size() == 1)
		{
			int winningIndex = m_vPlayers->front()->GetIndex();
			scoreManager::GetInstance().IncrementScore(winningIndex);

			if (scoreManager::GetInstance().HighestScore() == 3)
			{
				sceneManager::SetScene(new endScene());
			}
			else
			{
				//Load End Scene Here
				sceneManager::SetScene(new gameScene(nullptr, m_numPlayers));
			}
		}
		// Battery spawning
		m_batterySpawn->Update(_dT);
		if (m_batterySpawn->IsFinished()) {
			SummonBattery();
		}
	}
	for (auto i : *m_vBatteries)
	{
		i->Update(_dT);
	}

	m_tileManager->Update(_window, _dT);

	scoreManager::GetInstance().Update(_dT);

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

	if (m_startTimer != nullptr && !m_startTimer->IsFinished())
	{
		text(m_countdownText->GetText()->getPosition() - sf::Vector2f(330.0f, 50.0f),"Game Starting in", "Assets/arial.ttf", 150, scoreManager::GetInstance().WinningColor()).Render(_window);
		m_countdownText->GetText()->setFillColor(scoreManager::GetInstance().WinningColor());
		m_countdownText->Render(_window);
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

	// Draw resource bars
	for (auto p_it : *m_vPlayers)
	{
		p_it->DrawNitroResource(_window);
	}
}

/***********************
* SpawnBattery: Spawns the battery into the screen
* @author: Neel Kolhe
* @parameter: none
********************/
void gameScene::SummonBattery() 
{
	//float x = rand() % 900 + 300;
	//float y = rand() % 900 + 300;

	if (m_vBatteries->size() < 6)
	{
		int randomTile = rand() % m_tileManager->GetTileVector().size();

		if (m_tileManager->GetTile(randomTile)->GetBattery() == nullptr)
		{

			battery* bat = nullptr;

			int ch = rand() % 3;
			if(ch == 0)
			{
				bat = new battery(1,
					m_tileManager->GetTile(randomTile)->GetRect()->getPosition());
			}
			else if(ch == 1)
			{
				bat = new battery(2,
					m_tileManager->GetTile(randomTile)->GetRect()->getPosition());

			}
			else if(ch == 2)
			{
				bat = new battery(3,
					m_tileManager->GetTile(randomTile)->GetRect()->getPosition());

			}
			m_tileManager->GetTile(randomTile)->SetBattery(bat);
			m_vBatteries->push_back(bat);
		}
	}
	if (m_batterySpawn != nullptr)
	{
		delete m_batterySpawn;
	}
	m_batterySpawn = new timer(0.0f, 6.0f);
}
