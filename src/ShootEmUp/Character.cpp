#include "pch.h"
#include "Character.h"
#include <iostream>

Character::Character() : Entity()
{
	
}

void Character::Init(int up, std::string path, sf::Vector2f velocity, sf::Vector2f position)
{
	Entity::Init(path, velocity, position, 1);
	mUp = up;
}

//mUp--
void Character::TakeDamage()
{
	mUp--;
}

//mUp++
void Character::Heal()
{
	mUp++;
}

void Character::IsAlive()
{
	if (mUp < 1)
	{
		IsDead();
	}
}