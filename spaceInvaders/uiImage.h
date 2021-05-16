#ifndef __UI_IMAGE__H__
#define __UI_IMAGE__H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   uiImage.h
//  Description :   Class used to display images and resources
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <SFML/Graphics.hpp>
 // Local Includes 
#include "gameObject.h"
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 

class uiImage : public gameObject
{
public:
	uiImage(sf::Vector2f _pos, std::string _texLoc, bool _isBar);
	virtual ~uiImage();
	virtual void Update(float _dt);

	void SetPercentageDrawn(float _percentage); // Can be used for resource bars (used instead of GetSprite())
private:
	float tempClock;
	bool m_bIsBar;
};
#endif
