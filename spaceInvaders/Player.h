#ifndef __PLAYER_H__
#define __PLAYER_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   Player.h
//  Description :   Player class inherits from the gameObject class
//  Author      :   Himanshu Chawla
//  Mail        :   himanshu.chawla@mds.ac.nz
// 
 // Library Includes 
#include <vector>
 //Local includes
#include "gameObject.h"
#include "battery.h"
#include "timer.h"
#include "tManager.h"

class player :
	public gameObject
{
public:
	player(int _player);
	void death();
	~player();
	void AddForce(sf::Vector2f _dir);
	void AddPowerForrce(sf::Vector2f dir);
	void Update(float _dT);
	void SetPlayerVector(std::vector<player*>* _player);
	void SetBatteryVector(std::vector<battery*>* _player);

	bool IsReady();
	void SetReady(bool _ready);


	void OnTile(bool _isOnTile);
	void LeakingBattery();
	void DelayedDeathUpdate();
	bool GetWillDie() { return m_bWillDie; };
	void DrawCircleIndicator(sf::RenderWindow& _window);

	void SetTileVector(std::vector<tile*> _tiles);

	battery::eAbility m_ability;

private:
<<<<<<< Updated upstream
	bool m_isOnATile;
=======
	bool m_isOnATile[136];
	
	std::vector<tile*> m_vTilesList;
>>>>>>> Stashed changes

	bool m_ready;
	float m_delay = 0.0f;
	float m_disableTimer = 0.0f;
	bool m_disableControl;
	sf::Vector2f m_powerForce = sf::Vector2f(0.0f,0.0f);
	sf::Vector2f m_externVel = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f m_forceVel = sf::Vector2f(0.0f, 0.0f);
	float m_speed = 5.0f;
	float m_abilityTimer;
	inputManager* m_InputHandler;
	void PlayerCollision();
	void PlayerCollisionTile();
	void BatteryCollision();
	void BatteryImplementation(float _dt);
	std::vector<player*>* m_vPlayers;
	std::vector<battery*>* m_vBatteries;

	// Leaking battery variables
	bool m_bExphit; // Explosion hit player.
	bool m_bWillDie; // Player marked to die after time.
	float m_fDeathTimer; // Death timer.
	float m_fDeathDelay; // Amount of delay in death.
	float m_fExpRange = 150.0f;
	timer* m_DeathTimer;
	sf::CircleShape m_circleIndicator;
};

#endif