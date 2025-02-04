#include "pch.h"
#include "Ghost.h"
#include "define.h"

Ghost::Ghost() : Enemy(), Shadow()
{
    
}

void Ghost::Init(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position, float timeVisible)
{
    Enemy::Init(up, velocity, position);
    Shadow::Init(light, path);

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
    Twilight::Update(timeFrame);
    TimeVisibleLess(timeFrame);
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

SpriteManager* Ghost::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f Ghost::GetPosition()
{
    return getPosition();
}

void Ghost::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}

void Ghost::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (mIsHidden == IsShadow)
    {
        Twilight::draw(target, states);
    }
}

int Ghost::GetDifficulty()
{
    return GHOSTDIFFICULTY;
}
