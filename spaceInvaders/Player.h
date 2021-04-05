#pragma once
#include "gameObject.h"
class Player :
	public gameObject
{
public:
	
	Player(int player) :gameObject(player)
	{
		
		m_InputHandler = new inputManager(player);


		GetTexture()->loadFromFile("Assets/Players/P1.png");
		GetSprite()->setTexture(*GetTexture());
	}

	~Player();
	void Update(float _dT);

private:
	inputManager* m_InputHandler;



};

