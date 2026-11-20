#pragma once
#include "Scene.h"
class Level4 :public Scene
{
protected:

public:
	Level4();

	virtual void Init(Text* score, float timeGenerate);

	virtual void ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy);
	virtual int GetTypeScene();
};

