#include "pch.h"
#include "VoltBall.h"

VoltBall::VoltBall(): Shot(), Twilight()
{

}

void VoltBall::Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position)
{
    Shot::Init(type, path, light, velocity, position);
    Twilight::Init(light, path);
}

//mise a jour
void VoltBall::Update(float timeFrame)
{
    Shot::Update(timeFrame);
    MoveY();
    Twilight::Update(timeFrame);
}

bool VoltBall::CanCollideWithEntity(Twilight* entity)
{
    return true;
}

SpriteManager* VoltBall::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f VoltBall::GetPosition()
{
    return getPosition();
}

void VoltBall::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}