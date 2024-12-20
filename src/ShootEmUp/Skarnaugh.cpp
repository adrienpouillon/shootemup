#include "pch.h"
#include "Skarnaugh.h"
#include <iostream>

Skarnaugh::Skarnaugh(int up, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position) : Light(up, path, light, velocity, position), Shooter(Scene)
{//vide
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
    Texturing();
}

int Skarnaugh::GetType()
{
    return COLLIDESKARNAUGH;
}

int Skarnaugh::GetScore()
{
    return SCOREENEMY * (SKARNAUGHUP + ((int)SKARNAUGHVELOCITYX / 100) + (TIMESWAP - TIMESKARNAUGH));
}

void Skarnaugh::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (mIsHidden == false)
    {
        states.transform.combine(this->getTransform());
        target.draw(mSpriteManager->GetCurrentSprite(), states);
    }
}