#pragma once
#include "Scene.h"
#include "define.h"

class Level3 :public Scene
{
protected:

public:
	Level3(Text* score);

	virtual void ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy);
};

