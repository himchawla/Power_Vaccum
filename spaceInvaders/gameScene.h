#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "scene.h"
#include "gameObject.h"
#include <vector>
class gameScene : public scene
{
public:
	gameScene();
	~gameScene();
	virtual void Initialise(sf::RenderWindow& _window);
private:
	virtual void MainLoop(sf::RenderWindow& _window);
	virtual void Update(sf::RenderWindow& _window, float _dT);
	virtual void DrawBackground(sf::RenderWindow& _window);
	virtual void DrawObjects(sf::RenderWindow& _window);
	virtual void DrawUI(sf::RenderWindow& _window);

	std::vector<gameObject*>* m_vObjects;
};
#endif
