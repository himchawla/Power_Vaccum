#pragma once
#include <SFML/Graphics.hpp>
#include "uiImage.h"

class nitroManager : public uiImage
{

    nitroManager(sf::Vector2f _pos, std::string _barTexLoc, std::string _pointTexLoc, sf::Color _color);
    ~nitroManager();



};

