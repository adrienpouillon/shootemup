#include "pch.h"
#include "Aureon.h"
#include <iostream>


Aureon::Aureon() : Light(), Shooter()
{//vide
}

void Aureon::Init(int up, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position)
{
    Light::Init(up, path, light, velocity, position);
    Shooter::Init(Scene);
}

// mise a jour
void Aureon::Update(float timeFrame)
{
    //tirer
    Shooter::Update(timeFrame);
    Shooter::Shoot(TIMEAUREON, TYPEAUREON, getPosition());

    //fin 
    IsAlive();
    Entity::Update(timeFrame);
    Texturing();
}

int Aureon::GetType()
{
    return COLLIDEAUREON;
}

int Aureon::GetScore()
{
    return SCOREENEMY * (AUREONUP + ((int)AUREONVELOCITYX / 100) + (TIMESHOOT - TIMEAUREON));
}

void Aureon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (mIsHidden == false)
    {
        states.transform.combine(this->getTransform());
        target.draw(mSpriteManager->GetCurrentSprite(), states);
    }
}



