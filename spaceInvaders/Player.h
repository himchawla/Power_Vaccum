#pragma once
#include "gameObject.h"
class Player :
	public gameObject
{
public:
	Player(int player) :gameObject(player) {};
	~Player();
	void Update(float _dT);

};

