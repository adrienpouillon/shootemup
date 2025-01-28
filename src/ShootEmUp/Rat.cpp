#include "pch.h"
#include "Rat.h"
#include "define.h"
#include <iostream>


Rat::Rat() : Shadow()
{//vide
}

void Rat::Init(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position)
{
    Shadow::Init(up, path, light, velocity, position);
}

//mise a jour
void Rat::Update(float timeFrame)
{
    //fin
    IsAlive();
    Entity::Update(timeFrame);
    Texturing();
}

int Rat::GetType()
{
    return COLLIDERAT;
}

int Rat::GetScore()
{
    return SCOREENEMY * (RATUP + ((int)RATVELOCITYX/100));
}

void Rat::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (mIsHidden == false)
    {
        states.transform.combine(this->getTransform());
        target.draw(mSpriteManager->GetCurrentSprite(), states);
    }
}