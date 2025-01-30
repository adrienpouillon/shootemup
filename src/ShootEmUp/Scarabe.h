#pragma once
#include "Shadow.h"
#include "Define.h"
class Scarabe :public Enemy, public Shadow
{
protected:
	
public:
	Scarabe();

	virtual void Init(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position);

	void Update(float timeFrame);

	int GetType();

	int GetScore();

	SpriteManager* GetSpriteManager();

	sf::Vector2f GetPosition();

	void SetPosition(sf::Vector2f pos);

};

