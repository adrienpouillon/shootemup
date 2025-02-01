#include "pch.h"
#include "LightBall.h"
#include "Light.h"
#include "Ball.h"

LightBall::LightBall() : Shot(), Light()
{

}

void LightBall::Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position)
{
    Shot::Init(type, path, light, velocity, position);
    Twilight::Init(light, path);
}

//mise a jour
void LightBall::Update(float timeFrame)
{
    Shot::Update(timeFrame);
    Twilight::Update(timeFrame);
}

bool LightBall::CanCollideWithEntity(Twilight* entity)
{
    if (GetIsHidden() == entity->GetIsHidden())
    {
        return true;
    }
    return false;
}

int LightBall::GetType()
{
    return COLLIDELIGHTBALL;
}

SpriteManager* LightBall::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f LightBall::GetPosition()
{
    return getPosition();
}

void LightBall::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}