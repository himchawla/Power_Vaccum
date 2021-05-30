// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   menuScene.cpp
//  Description :   A lobby scene where players tag in and out of the game before playing.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
#include "lobbyScene.h"
#include "sceneManager.h"
 // This Include 
#include "menuScene.h"
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

menuScene::menuScene()
{
	m_texBackground = new sf::Texture();
	m_sprBackground = new sf::Sprite();
	m_imgLogo = new uiImage(sf::Vector2f(960, 200), "Assets/Menu/TempLogo.png", false);
	m_delayTimer = new timer(0.3f, 0.0f);
	m_bigDelayTimer = new timer(1.0f, 0.0f);
}

menuScene::~menuScene()
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
	if (m_imgLogo != nullptr)
	{
		delete m_imgLogo;
		m_imgLogo = 0;
	}
}

/***********************
* Initialise: Initialise scene.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void menuScene::Initialise(sf::RenderWindow& _window)
{
	// Create background
	m_texBackground->loadFromFile("Assets/mainmenuBG.png");
	m_sprBackground->setTexture(*m_texBackground);
	m_sprBackground->setPosition(0, 0);

	audioManager::GetInstance().SetMusic("GameMusic.wav");
	audioManager::GetInstance().GetMusic()->play();

	// Create Buttons
	for (int i = 0; i < 3; i++)
	{
		m_vButtons.push_back(new button(550 + m_v2Offset.x, 500 + m_v2Offset.y * i, i));
		if (i == 0)
		{
			m_vButtons[i]->AssignImage("Assets/Start.png");
		}
	}


}

/***********************
* MainLoop: Loop which calls update and render functions.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void menuScene::MainLoop(sf::RenderWindow& _window)
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
void menuScene::Update(sf::RenderWindow& _window, float _dT)
{
	
	m_delayTimer->Update(_dT);
	m_bigDelayTimer->Update(_dT);
	m_imgLogo->Update(_dT);

	// Go to lobby
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		sceneManager::SetScene(new lobbyScene());
	}

	for (auto&  m_vButton : m_vButtons)
	{
		m_vButton->Update(_dT);
		m_vButton->isMouseHere(_window);
		


		if (m_vButton->Clicked() == true && m_vButton->getWeight() == 0) // Start Button
		{
			sceneManager::SetScene(new lobbyScene());
		}
	}

	SelectionController();
	m_imgLogo->Update(_dT);


}

/***********************
* DrawBackground: Draws all background objects.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void menuScene::DrawBackground(sf::RenderWindow& _window)
{
	// Draw background
	_window.draw(*m_sprBackground);
}

/***********************
* DrawObjects: Draws all objects that are not in the background or UI. 
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void menuScene::DrawObjects(sf::RenderWindow& _window)
{
	m_imgLogo->Draw(_window);
}

/***********************
* DrawUI: Draws all UI elements.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void menuScene::DrawUI(sf::RenderWindow& _window)
{
	// Draw UI elements
	for (int i = 0; i < m_vButtons.size(); i++)
	{
		_window.draw(*m_vButtons[i]->GetRect());
		if (m_vButtons[i]->m_buttonSprite = nullptr)
			m_vButtons[i]->m_buttonSprite->Draw(_window);

	}

}

void menuScene::SelectionController()
{
	for (int i = 0; i < 4; i++)
	{
		sf::Vector2i result;


		for (auto it : m_vButtons)
		{
			if (it->isHovering())
			{
				if (!m_vButtons[m_controllerSelection]->isHovering())
					m_vButtons[m_controllerSelection]->SetColor(sf::Color::White);
				return;
			}
		}
		result = inputManager::GetDPAD(i);
		for (int j = 0; j < m_controllerSelection; j++)
		{
			m_vButtons[j]->SetColor(sf::Color::White);
		}
		m_vButtons[m_controllerSelection]->SetColor(sf::Color::Red);



		if (result.y == 1 && m_controllerSelection > 0 && m_delayTimer->IsFinished())
		{
			for (int k = 0; k < 4; k++)	m_wasPressed[k] = false;
			m_controllerSelection--;
			m_delayTimer->ResetTimer();
			m_bigDelayTimer->ResetTimer();
		}
		if (result.y == -1 && m_controllerSelection < m_vButtons.size() - 1 && m_delayTimer->IsFinished())
		{
			for (int k = 0; k < 4; k++)	m_wasPressed[k] = false;
			m_controllerSelection++;
			m_delayTimer->ResetTimer();
			m_bigDelayTimer->ResetTimer();
		}

		if(inputManager::GetControllerButton(0, i) && m_bigDelayTimer->IsFinished())
		{
			m_wasPressed[i] = true;
			
		}
		for (int k = 0; k < 4; k++)
		{
			if (m_wasPressed[k])
			{
				m_vButtons[m_controllerSelection]->SetColor(sf::Color::Blue);
				break;;
			}
		}

		
		if(m_wasPressed[i] && !inputManager::GetControllerButton(0, i))
		{
			m_vButtons[m_controllerSelection]->Clicked(true);
		}
		
	}
}
