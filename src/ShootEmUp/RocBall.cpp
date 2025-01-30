#include "pch.h"
#include "RocBall.h"

RocBall::RocBall() : Shot(), Twilight()
{

}

void RocBall::Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position)
{
    Shot::Init(type, path, light, velocity, position);
    Twilight::Init(light, path);
}

//mise a jour
void RocBall::Update(float timeFrame)
{
    Shot::Update(timeFrame);
    Twilight::Update(timeFrame);
}

void RocBall::TouchEntity()
{
    //persistant
}

bool RocBall::CanCollideWithEntity(Twilight* Entity)
{
    return true;
}

SpriteManager* RocBall::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f RocBall::GetPosition()
{
    return getPosition();
}

void RocBall::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}