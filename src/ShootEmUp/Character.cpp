#include "pch.h"
#include "Character.h"
#include "define.h"
#include <iostream>

Character::Character() : Entity()
{
	
}

void Character::Init(int up, sf::Vector2f velocity, sf::Vector2f position)
{
	Entity::Init(velocity, position);
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