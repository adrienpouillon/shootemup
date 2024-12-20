#pragma once
#include "Scene.h"
#include "define.h"

class Level1 : public Scene
{
protected:
	
public:
	Level1(Text* score);

	virtual void ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy);
};

