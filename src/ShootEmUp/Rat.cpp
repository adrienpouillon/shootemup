#include "pch.h"
#include "Rat.h"
#include "define.h"
#include <iostream>


Rat::Rat() : Enemy(), Shadow()
{//vide
}

void Rat::Init(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position)
{
    Enemy::Init(up, velocity, position);
    Shadow::Init(light, path);
}

//mise a jour
void Rat::Update(float timeFrame)
{
    //fin
    IsAlive();
    Entity::Update(timeFrame);
    Twilight::Update(timeFrame);
}

int Rat::GetType()
{
    return COLLIDERAT;
}

int Rat::GetScore()
{
    return SCOREENEMY * (RATUP + ((int)RATVELOCITYX/100));
}

SpriteManager* Rat::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f Rat::GetPosition()
{
    return getPosition();
}

void Rat::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}

int Rat::GetDifficulty()
{
    return RATDIFFICULTY;
}

