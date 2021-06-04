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
	m_startPos = new gameObject();
	m_startPos->SetSpriteFromFile("Assets/ReadyUpZone.png", sf::Vector2<float>(512.0f, 512.0f));
	m_startPos->transform.m_Position = sf::Vector2f(960.0f, 540.0f);
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
	if (m_vPlayers != nullptr)
	{
		if (m_vPlayers->size() < 1)
		{
			delete m_vPlayers;
			m_vPlayers = 0;
		}
	}

	// Delete buttons
	std::vector<button*>::iterator b_it = m_vButtons.begin();
	while (b_it != m_vButtons.end())
	{
		// Delete vector contents
		delete* b_it;
		b_it = m_vButtons.erase((b_it));
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

	// Create Buttons
	
		
	//m_vButtons.push_back(new button(550 + m_v2Offset.x, 700 + m_v2Offset.y * 1, 1, "Assets/MainMenu"));
	//m_vButtons[0]->setButtonText("Main Menu", 45);
		
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
	m_startPos->Update(_dT);
	for(auto& _button:m_vButtons)
	{
		_button->Update(_dT);
	}
	
	for (int i = 0; i < 4; i++)
	{
		m_playerStatus[i].Update(_dT);
		if (inputManager::FaceButtonPressed(i) && !m_hasJoined[i])
		{
			m_numPlayers++;
			if (m_numPlayers > 1 && !m_canStart)
			{
				m_canStart = true;
			}
			m_hasJoined[i] = true;
			std::cout << "Player " << i << " has joined the game";
			player* newPlayer = new player(i);
			newPlayer->SetStartPos(m_startPos);
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
			
			newPlayer->gameObject::Update(_dT);

			newPlayer->SetPlayerVector(m_vPlayers);
			m_vPlayers->push_back(newPlayer);
		}


	}

	

	// Start game
	
	for (auto i : *m_vPlayers)
	{
		i->LobbyUpdate(_dT);
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
		audioManager::GetInstance().SetMusic("GameMusic.wav");
		audioManager::GetInstance().GetMusic()->play();
		audioManager::GetInstance().PlaySound("ButtonPress");
		sceneManager::SetScene(new gameScene(m_vPlayers));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		audioManager::GetInstance().SetMusic("GameMusic.wav");
		audioManager::GetInstance().GetMusic()->play();
		audioManager::GetInstance().PlaySound("ButtonPress");
		sceneManager::SetScene(new gameScene(nullptr));
	}


	//for (auto& m_vButton : m_vButtons)
	//{
	//	m_vButton->Update(_dT);
	//	m_vButton->isMouseHere(_window);



	//	if (m_vButton->Clicked() == true && m_vButton->getWeight() == 0) // Start Button
	//	{
	//		if (m_canStart && m_numPlayers > 1)
	//		{
	//			sceneManager::SetScene(new gameScene(m_vPlayers));
	//		}
	//		else
	//		{
	//			sceneManager::SetScene(new gameScene(nullptr));
	//		}
	//	}
	//	else if (m_vButton->Clicked() == true && m_vButton->getWeight() == 1) // Back to Main Menu Button
	//	{
	//		sceneManager::SetScene(new menuScene());
	//	}
	//}
	
		
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
	for (int i = 0; i < 4; i++)
	{
		m_playerStatus[i].Draw(_window);
	}

	m_startPos->Draw(_window);
	for (auto i : *m_vPlayers)
	{
		i->Draw(_window);
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
	for (int i = 0; i < m_vButtons.size(); i++)
	{

		m_vButtons[i]->Draw(_window);
		
	}
}
