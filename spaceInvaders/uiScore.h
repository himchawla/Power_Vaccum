#ifndef __UI_SCORE_H__
#define __UI_SCORE_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   uiScore.h
//  Description :   Score display used to show users the current score.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
#include "uiImage.h"
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 
class uiScore :
    public uiImage
{
public:
    uiScore(sf::Vector2f _pos, std::string _barTexLoc, std::string _pointTexLoc, sf::Color _color);
    ~uiScore();

    virtual void Update(float _dT);
    void Draw(sf::RenderWindow& _window);
    void SetScore(int _score);
private:
    int m_iScore;
    uiImage* m_scorePoints[3];
};

#endif