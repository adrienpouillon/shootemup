#include "pch.h"
#include "Scarabe.h"

Scarabe::Scarabe() :Shadow()
{
}

void Scarabe::Init(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position)
{
    Shadow::Init(up, path, light, velocity, position);
}

void Scarabe::Update(float timeFrame)
{
    //fin
    IsAlive();
    Entity::Update(timeFrame);
    Texturing();
}

int Scarabe::GetType()
{
    return COLLIDESCARABE;
}

int Scarabe::GetScore()
{
    return SCOREENEMY * (SCARABEUP + ((int)SCARABEVELOCITYX / 100));
}

void Scarabe::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (mIsHidden == false)
    {

        states.transform.combine(this->getTransform());
        target.draw(mSpriteManager->GetCurrentSprite(), states);
    }
}
