#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   gameObject.h
//  Description :   Parent object for all gameobjects in game.
//  Author      :   William de Beer | Himanshu Chawla
//  Mail        :   William.Beer@mds.ac.nz | himanshu.chawla@mds.ac.nz
// 
 // Library Includes 
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "inputManager.h"

 // Local Includes 
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

#define PI 3.14159265
class gameObject
{
public:
	
	gameObject(int player);
	gameObject();
	virtual ~gameObject();
	bool n = false;
	struct Tranform
	{
		sf::Vector2f m_Position;
		sf::Vector2f m_Velocity;
		sf::Vector2f m_Accelaration;
		sf::Vector2f m_Force;

		sf::Vector2f m_Friction;
		
		
		float m_Rotation;
		float m_Mass;


		bool m_IsKinematic;
	};

	

	Tranform transform;

	void Update(float _dT);

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f _position);

	sf::Sprite* GetSprite();
	void SetSprite(sf::Sprite* _sprite);

	sf::CircleShape* GetCircle();
	void SetCircle(sf::CircleShape* _circle);

	sf::Texture* GetTexture();
	void setTexture(sf::Texture* _texture);


	float Magnitude(sf::Vector2f vec);
private:
	sf::CircleShape* m_TempCirc;
	sf::Sprite* m_Sprite;
	sf::Texture* m_Texture;
	sf::Vector2f m_2fPosition;
	float m_fRotation;
};
#endif
