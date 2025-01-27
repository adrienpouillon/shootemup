#include "pch.h"
#include "Ghost.h"
#include "define.h"

Ghost::Ghost(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position, int timeVisible) : Shadow(up, path, light, velocity, position)
{
    mTimeVisible = timeVisible;
    mTimeVisibleStay = mTimeVisible;
    IsShadow = true;
}

void Ghost::TimeVisibleLess(int n)
{
    mTimeVisibleStay -= n;
    if (mTimeVisibleStay < 0)
    {
        IsShadow = !IsShadow;
    }
}

//mise a jour
void Ghost::Update(float timeFrame)
{
    //fin
    IsAlive();
    Entity::Update(timeFrame);
    TimeVisibleLess(timeFrame);
    Texturing();
}

int Ghost::GetType()
{
    return COLLIDEGHOST;
}

bool Ghost::GetIsHidden()
{
    return mIsHidden == IsShadow;
}

int Ghost::GetScore()
{
    return SCOREENEMY * (GHOSTUP + ((int)GHOSTVELOCITYX / 100));
}

void Ghost::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (mIsHidden == IsShadow)
    {
        states.transform.combine(this->getTransform());
        target.draw(mSpriteManager->GetCurrentSprite(), states);
    }
}
