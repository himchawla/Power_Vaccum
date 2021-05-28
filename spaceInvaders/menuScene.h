#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   menuScene.h
//  Description :   A lobby scene where players tag in and out of the game before playing.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
#include "scene.h"
#include "uiImage.h"
#include "button.h"
#include "timer.h"
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

class menuScene : public scene
{
public:
	menuScene();
	virtual ~menuScene();
	virtual void Initialise(sf::RenderWindow& _window);
	virtual void MainLoop(sf::RenderWindow& _window);
private:
	virtual void Update(sf::RenderWindow& _window, float _dT);
	virtual void DrawBackground(sf::RenderWindow& _window);
	virtual void DrawObjects(sf::RenderWindow& _window);
	virtual void DrawUI(sf::RenderWindow& _window);

	sf::Texture* m_texBackground;
	sf::Sprite* m_sprBackground;

	// Buttons in a Vector
	std::vector<button*> m_vButtons;
	int m_controllerSelection = 0;
	timer *m_delayTimer;
	bool m_wasPressed[4];
	timer *m_bigDelayTimer;

	void SelectionController();
	
	sf::Vector2f m_v2Offset = sf::Vector2f(400.0f, 200.0f);
	int m_iWeight = 0; // Use Input manager, delete this later.

	uiImage* m_imgLogo;
};
#endif