#pragma once

#include "Entity.h"

class Character : public Entity
{
protected:
	int mUp;

public:
	Character(int up, std::string path, sf::Vector2f velocity, sf::Vector2f position);

	void TakeDamage();

	void Heal();

	void IsAlive();
};