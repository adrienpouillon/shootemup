#include "pch.h"
#include "Skarnaugh.h"
#include <iostream>

Skarnaugh::Skarnaugh() : Enemy(), Light(), Shooter()
{//vide
}

void Skarnaugh::Init(int up, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position)
{
    Enemy::Init(up, velocity, position);
    Light::Init(light, path);
    Shooter::Init(Scene);
}

// mise a jour
void Skarnaugh::Update(float timeFrame)
{
    //tirer
    Shooter::Update(timeFrame);
    Shooter::Swap(TIMESKARNAUGH, mLight);

    //fin 
    IsAlive();
    Entity::Update(timeFrame);
    Twilight::Update(timeFrame);
}

int Skarnaugh::GetType()
{
    return COLLIDESKARNAUGH;
}

int Skarnaugh::GetScore()
{
    return SCOREENEMY * (SKARNAUGHUP + ((int)SKARNAUGHVELOCITYX / 100) + (TIMESWAP - TIMESKARNAUGH));
}

SpriteManager* Skarnaugh::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f Skarnaugh::GetPosition()
{
    return getPosition();
}

void Skarnaugh::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}

int Skarnaugh::GetDifficulty()
{
    return SKARNAUGHDIFFICULTY;
}

