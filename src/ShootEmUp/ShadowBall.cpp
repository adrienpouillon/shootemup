#include "pch.h"
#include "ShadowBall.h"

ShadowBall::ShadowBall() : Shot(), Shadow()
{

}

void ShadowBall::Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position)
{
    Shot::Init(type, path, light, velocity, position);
    Shadow::Init(light, path);
}

//mise a jour
void ShadowBall::Update(float timeFrame)
{
    Shot::Update(timeFrame);
    Shadow::Update(timeFrame);
}

bool ShadowBall::CanCollideWithEntity(Twilight* entity)
{
    if (GetIsHidden() == entity->GetIsHidden())
    {
        return true;
    }
    return false;
}

SpriteManager* ShadowBall::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f ShadowBall::GetPosition()
{
    return getPosition();
}

void ShadowBall::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}