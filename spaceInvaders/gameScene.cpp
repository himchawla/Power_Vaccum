#include "gameScene.h"

gameScene::gameScene()
{
	m_vObjects = new std::vector<gameObject*>();
}

gameScene::~gameScene()
{
	std::vector<gameObject*>::iterator it = m_vObjects->begin();
	while (it != m_vObjects->end())
	{
		// delete vector contents
	}
}

void gameScene::Initialise(sf::RenderWindow& _window)
{
	gameObject* temp = new gameObject();
	temp->SetCircle(new sf::CircleShape(100.0f));
	temp->GetCircle()->setFillColor(sf::Color::Green);
	temp->SetPosition(sf::Vector2f(800, 800));
	m_vObjects->push_back(temp);

	MainLoop(_window);
}

void gameScene::MainLoop(sf::RenderWindow& _window)
{
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

void gameScene::Update(sf::RenderWindow& _window, float _dT)
{
	std::vector<gameObject*>::iterator it = m_vObjects->begin();
	while (it != m_vObjects->end())
	{
		(*it)->Update(_dT);
	}
}

void gameScene::DrawBackground(sf::RenderWindow& _window)
{
}

void gameScene::DrawObjects(sf::RenderWindow& _window)
{
	std::vector<gameObject*>::iterator it = m_vObjects->begin();
	while (it != m_vObjects->end())
	{
		_window.draw(*(*it)->GetSprite());
	}
}

void gameScene::DrawUI(sf::RenderWindow& _window)
{
}
