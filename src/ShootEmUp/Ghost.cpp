#include "pch.h"
#include "Ghost.h"
#include "define.h"

Ghost::Ghost() : Shadow()
{
    
}

void Ghost::Init(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position, float timeVisible)
{
    Shadow::Init(up, path, light, velocity, position);
    mTimeVisible = timeVisible;
    mTimeVisibleStay = mTimeVisible - (mTimeVisible / 2);
    IsShadow = true;
    velocityVisible = velocity;
    velocityInvisible = velocity / 8.f;
}

void Ghost::TimeVisibleLess(float n)
{
    mTimeVisibleStay -= n*3;
    if (mTimeVisibleStay < 0)
    {
        IsShadow = !IsShadow;
        mTimeVisibleStay = mTimeVisible;
    }
}

//mise a jour
void Ghost::Update(float timeFrame)
{
    //fin
    IsAlive();
    UpdateVelocity();
    Entity::Update(timeFrame);
    TimeVisibleLess(timeFrame);
    Texturing();
}

void Ghost::UpdateVelocity()
{
    if (GetIsHidden())
    {
        SetVelocity(velocityVisible);
    }
    else
    {
        SetVelocity(velocityInvisible);
    }
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
