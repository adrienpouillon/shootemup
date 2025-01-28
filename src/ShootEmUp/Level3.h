#pragma once
#include "Scene.h"
#include "define.h"

class Level3 :public Scene
{
protected:

public:
	Level3(Text* score, float timeGenerate);

	virtual void ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy);
	virtual int GetTypeScene();
};

