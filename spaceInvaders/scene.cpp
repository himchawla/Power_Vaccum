#include "scene.h"

scene::scene()
{
}

scene::~scene()
{
}

void scene::Initialise(sf::RenderWindow& _window)
{
	MainLoop(_window);
}

void scene::MainLoop(sf::RenderWindow& _window)
{

}

void scene::Render(sf::RenderWindow& _window)
{
	_window.clear();

	DrawBackground(_window);
	DrawObjects(_window);
	DrawUI(_window);

	_window.display();
}

