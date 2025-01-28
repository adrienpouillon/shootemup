#pragma once
#include "Scene.h"
#include "define.h"

class Level1 : public Scene
{
protected:
	
public:
	Level1();
	
	virtual void Init(Text* score, float timeGenerate);

	virtual void ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy);
	virtual int GetTypeScene();
};

