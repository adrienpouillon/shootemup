#pragma once
#include "Twilight.h"
#include "Character.h"

class Enemy : public Character
{
protected:
	

public:
	Enemy();

	virtual void Init(int up, sf::Vector2f velocity, sf::Vector2f position);

	void Move(float timeFrame) override;

	virtual SpriteManager* GetSpriteManager() = 0;
};