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
}

gameScene::~gameScene()
{
	std::vector<gameObject*>::iterator it = m_vObjects->begin();
	while (it != m_vObjects->end())
	{
		// Delete vector contents
		delete* it;
		it = m_vObjects->erase((it));
	}
	if (m_vObjects != nullptr)
	{
		delete m_vObjects;
		m_vObjects = 0;
	}
}

/***********************
* Initialise: Initialise scene and call MainLoop.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::Initialise(sf::RenderWindow& _window)
{
	gameObject* temp = new gameObject();
	temp->SetCircle(new sf::CircleShape(100.0f));
	temp->GetCircle()->setFillColor(sf::Color::Green);
	temp->SetPosition(sf::Vector2f(800, 800));
	m_vObjects->push_back(temp);

	MainLoop(_window);
}

/***********************
* MainLoop: Loop which calls update and render functions.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::MainLoop(sf::RenderWindow& _window)
{
	// Start clock
	sf::Clock clock;
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
* @author: William de Beer
* @parameter: Reference to render window, Delta time.
********************/
void gameScene::Update(sf::RenderWindow& _window, float _dT)
{
	std::vector<gameObject*>::iterator it = m_vObjects->begin();
	while (it != m_vObjects->end())
	{
		(*it)->Update(_dT);
		it++;
	}
}

/***********************
* DrawBackground: Draws all background objects.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::DrawBackground(sf::RenderWindow& _window)
{
	//// Vector of background objects 
	//std::vector<gameObject*>::iterator it = m_vObjects->begin();
	//while (it != m_vObjects->end())
	//{
	//	if ((*it)->GetSprite() != nullptr)
	//	{
	//		_window.draw(*(*it)->GetSprite());
	//	}
	//	else if ((*it)->GetCircle() != nullptr) // Debug circle
	//	{
	//		_window.draw(*(*it)->GetCircle());
	//	}
	//	it++;
	//}
}

/***********************
* DrawObjects: Draws all objects that are not in the background or UI. This includes players, powerups and tiles.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::DrawObjects(sf::RenderWindow& _window)
{
	// Vector of objects
	std::vector<gameObject*>::iterator it = m_vObjects->begin();
	while (it != m_vObjects->end())
	{
		if ((*it)->GetSprite() != nullptr)
		{
			_window.draw(*(*it)->GetSprite());
		}
		else if ((*it)->GetCircle() != nullptr) // Debug circle
		{
			_window.draw(*(*it)->GetCircle());
		}
		it++;
	}
}

/***********************
* DrawUI: Draws all UI elements.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::DrawUI(sf::RenderWindow& _window)
{
	// Vector of UI elements
}
