#include "pch.h"
#include "Enemy.h"
#include <iostream>


Enemy::Enemy() : Character()
{
}

void Enemy::Init(int up, sf::Vector2f velocity, sf::Vector2f position)
{
	Character::Init(up, velocity, position);
}

//deplacement
void Enemy::Move(float timeFrame)
{
	Entity::Move(timeFrame);
}
