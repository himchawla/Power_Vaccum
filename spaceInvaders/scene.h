#ifndef __SCENE_H__
#define __SCENE_H__

#include <SFML/Graphics.hpp>

class scene
{
public:
	scene();
	virtual ~scene();
	virtual void Initialise(sf::RenderWindow& _window);
protected:
	virtual void MainLoop(sf::RenderWindow& _window);
	virtual void Render(sf::RenderWindow& _window);
	virtual void Update(sf::RenderWindow& _window, float _dT) = 0;
	virtual void DrawBackground(sf::RenderWindow& _window) = 0;
	virtual void DrawObjects(sf::RenderWindow& _window) = 0;
	virtual void DrawUI(sf::RenderWindow& _window) = 0;
};
#endif
