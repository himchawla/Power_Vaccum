#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "scene.h"

class sceneManager
{
public:
	static void SetScene(scene* _scene);
	static void Update(sf::RenderWindow& _window);
	static void Shutdown();

private:
	static scene* m_CurrentScene;
	static scene* m_SceneBuffer;
};

#endif