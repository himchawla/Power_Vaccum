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
	gameObject();
	virtual ~gameObject();
	bool n = false;
	struct Transform
	{
		sf::Vector2f m_Position;
		sf::Vector2f m_Velocity;
		sf::Vector2f m_Acceleration;
		sf::Vector2f m_Force;

		sf::Vector2f m_Friction;
		
		float m_Rotation;
		float m_Mass;

		bool m_IsKinematic;
	};
	Transform transform;

	bool IsEnabled();

	void Update(float _dT);

	void Draw(sf::RenderWindow& _window);

	sf::Sprite* GetSprite();
	void SetSprite(sf::Sprite* _sprite);

	sf::Texture* GetTexture();
	void SetTexture(sf::Texture* _texture);

	void SetSpriteFromFile(std::string _address, sf::Vector2f _size = sf::Vector2f(64.0f,64.0f));
	void SetSpriteFromFile_NoMod(std::string _address, sf::Vector2f _size);

	void Destroy();

	float Magnitude(sf::Vector2f _vec);
private:
	bool enabled;
	sf::Sprite* m_Sprite;
	sf::Texture* m_Texture;
};
#endif
