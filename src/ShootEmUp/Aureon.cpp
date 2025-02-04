#include "pch.h"
#include "Aureon.h"

#include "Ball.h"
#include "VoltBall.h"
#include "LightBall.h"
#include "ShadowBall.h"
#include "RocBall.h"
#include "MultiBall.h"


Aureon::Aureon() :Enemy(), Light(), Shooter()
{//vide
}

void Aureon::Init(int up, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position)
{
    Enemy::Init(up, velocity, position);
    Light::Init(light, path);
    Shooter::Init(Scene);
}

// mise a jour
void Aureon::Update(float timeFrame)
{
    //tirer
    Shooter::Update(timeFrame);
    if (Ball* ball = Shoot<Ball>(TIMEAUREON))
    {
        ball->Init(TYPEAUREON, SHOTPATH, mLight, SHOTVELOCITY, GetPosition());
    }
    //fin 
    IsAlive();
    Entity::Update(timeFrame);
    Twilight::Update(timeFrame);
}

int Aureon::GetType()
{
    return COLLIDEAUREON;
}

int Aureon::GetScore()
{
    return SCOREENEMY * (AUREONUP + ((int)AUREONVELOCITYX / 100) + (TIMESHOOT - TIMEAUREON));
}

SpriteManager* Aureon::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f Aureon::GetPosition()
{
    return getPosition();
}

void Aureon::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}

int Aureon::GetDifficulty()
{
    return AUREONDIFFICULTY;
}




