#ifndef __UI_IMAGE__H__
#define __UI_IMAGE__H__

#include <SFML/Graphics.hpp>
#include "gameObject.h"

class uiImage : public gameObject
{
public:
	uiImage(sf::Vector2f _pos, std::string _texLoc);
	virtual ~uiImage();
	virtual void Update(float _dt);

	void SetPercentageDrawn(float _percentage, bool _fillFromLeft); // Can be used for resource bars (used instead of GetSprite())
private:
	float tempClock;
};
#endif
