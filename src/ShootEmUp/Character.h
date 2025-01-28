#pragma once

#include "Entity.h"

class Character : public Entity
{
protected:
	int mUp;

public:
	Character();

	virtual void Init(int up, std::string path, sf::Vector2f velocity, sf::Vector2f position);

	virtual void TakeDamage();

	void Heal();

	void IsAlive();
};