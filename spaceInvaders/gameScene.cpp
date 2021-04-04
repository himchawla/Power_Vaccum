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

	std::vector<gameObject*>::iterator p_it = m_vPlayers->begin();
	while (p_it != m_vPlayers->end())
	{
		// Delete vector contents
		delete* it;
		it = m_vPlayers->erase((it));
	}
	if (m_vPlayers != nullptr)
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

	MainLoop(_window);
}

/***********************
* MainLoop: Loop which calls update and render functions.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameScene::MainLoop(sf::RenderWindow& _window)
{
	gameObject* temp = new gameObject();
	temp->SetCircle(new sf::CircleShape(100.0f));
	temp->GetCircle()->setFillColor(sf::Color::Green);
	temp->SetPosition(sf::Vector2f(800, 800));
	m_vPlayers->push_back(temp);


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
			if (event.type == sf::Event::KeyPressed && event.key.code != sf::Keyboard::Space)
			{
				key = event.key.code;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code != sf::Keyboard::Space)
			{
				key = sf::Keyboard::Add;
			}

			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				key = sf::Keyboard::Space;
			}

		}

		switch (key)
		{

		case sf::Keyboard::A:
		{
			temp->transform.m_Velocity = sf::Vector2f(-100.0f, 0.0f);
		}
		break;

		case sf::Keyboard::D:
			break;
		case sf::Keyboard::E:
			break;

		case sf::Keyboard::S:
			break;

		case sf::Keyboard::W:
			break;

		case sf::Keyboard::Space:
		{
			temp->transform.m_Force = sf::Vector2f(2.0f, 0.0f);
		}
		break;



		default:
		{
			temp->transform.m_Velocity = sf::Vector2f(0.0f, 0.0f);
		}
		break;
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

	std::vector<gameObject*>::iterator p_it = m_vPlayers->begin();
	while (p_it != m_vPlayers->end())
	{
		if ((*p_it)->GetSprite() != nullptr)
		{
			_window.draw(*(*p_it)->GetSprite());
		}
		else if ((*p_it)->GetCircle() != nullptr) // Debug circle
		{
			_window.draw(*(*p_it)->GetCircle());
		}
		p_it++;
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
