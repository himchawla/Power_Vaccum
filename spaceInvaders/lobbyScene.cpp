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

	temp1 = new uiImage(sf::Vector2f(100, 100), "Assets/TempBar.png");
	temp2 = new uiImage(sf::Vector2f(800, 100), "Assets/TempBar.png");
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
	m_texBackground->loadFromFile("Assets/lobbyBG.png");
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

	// Start game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		sceneManager::SetScene(new gameScene());
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
* DrawObjects: Draws all objects that are not in the background or UI. This includes players, powerups and tiles.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void lobbyScene::DrawObjects(sf::RenderWindow& _window)
{
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
