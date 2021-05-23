// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   endScene.cpp
//  Description :   A end scene which will display who won the match.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include<iostream>
 // Local Includes 
#include "menuScene.h"
#include "sceneManager.h"
 // This Include 
#include "endScene.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

endScene::endScene()
{
	m_texBackground = new sf::Texture();
	m_sprBackground = new sf::Sprite();
}

endScene::~endScene()
{
}

/***********************
* Initialise: Initialise scene.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void endScene::Initialise(sf::RenderWindow& _window)
{
	// Create background
	m_texBackground->loadFromFile("Assets/endBG.png");
	m_sprBackground->setTexture(*m_texBackground);
	m_sprBackground->setPosition(0, 0);

	sf::Color color = scoreManager::GetInstance().WinningColor();
	m_sprBackground->setColor(sf::Color(color.r / 0.5f, color.g / 0.5f, color.b / 0.5f));

	m_fntWinner.loadFromFile("Assets/arial.ttf");
	
	m_txtWinner.setFont(m_fntWinner);
	m_txtWinner.setString("PLAYER " + std::to_string(scoreManager::GetInstance().WinningIndex() + 1) + " WINS");
	m_txtWinner.setCharacterSize(96);
	m_txtWinner.setPosition(580, 200);
	m_txtWinner.setOrigin(0.0f, 24.0f);


	scoreManager::GetInstance().EndPositioning();
}

/***********************
* MainLoop: Loop which calls update and render functions.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void endScene::MainLoop(sf::RenderWindow& _window)
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
void endScene::Update(sf::RenderWindow& _window, float _dT)
{
	scoreManager::GetInstance().Update(_dT);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		sceneManager::SetScene(new menuScene());
	}
}

/***********************
* DrawBackground: Draws all background objects.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void endScene::DrawBackground(sf::RenderWindow& _window)
{
	// Draw background
	_window.draw(*m_sprBackground);
}

/***********************
* DrawObjects: Draws all objects that are not in the background or UI.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void endScene::DrawObjects(sf::RenderWindow& _window)
{
}

/***********************
* DrawUI: Draws all UI elements.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void endScene::DrawUI(sf::RenderWindow& _window)
{
	// Draw UI elements
	scoreManager::GetInstance().DrawUI(_window);
	_window.draw(m_txtWinner);
}