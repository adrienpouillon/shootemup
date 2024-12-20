#include "pch.h"
#include "Enemy.h"
#include <iostream>


Enemy::Enemy(int up, std::string path, sf::Vector2f velocity, sf::Vector2f position) : Character(up, path, velocity, position)
{//vide
}

//deplacement
void Enemy::Move(float timeFrame)
{
	Entity::Move(timeFrame);
}
