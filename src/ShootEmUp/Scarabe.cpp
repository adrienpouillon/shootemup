#include "pch.h"
#include "Scarabe.h"

Scarabe::Scarabe() :Enemy(), Shadow()
{
}

void Scarabe::Init(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position)
{
    Enemy::Init(up, velocity, position);
    Shadow::Init(light, path);
}

void Scarabe::Update(float timeFrame)
{
    //fin
    IsAlive();
    Entity::Update(timeFrame);
    Twilight::Update(timeFrame);
}

int Scarabe::GetType()
{
    return COLLIDESCARABE;
}

int Scarabe::GetScore()
{
    return SCOREENEMY * (SCARABEUP + ((int)SCARABEVELOCITYX / 100));
}

SpriteManager* Scarabe::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f Scarabe::GetPosition()
{
    return getPosition();
}

void Scarabe::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}

int Scarabe::GetDifficulty()
{
    return SCARABEDIFFICULTY;
}


