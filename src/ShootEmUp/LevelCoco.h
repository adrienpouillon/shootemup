#pragma once
#include "Scene.h"
class LevelCoco :public Scene
{
protected:

public:
	LevelCoco();

	virtual void Init(Text* score, float timeGenerate);

	virtual void ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy);
	virtual int GetTypeScene();
};

