#pragma once
#include "Scene.h"
#include "define.h"
class Level2 :public Scene
{
protected:

public:
	Level2(Text* score);

	virtual void ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy);
	virtual int GetTypeScene();
};

