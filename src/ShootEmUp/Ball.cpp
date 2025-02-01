#include "pch.h"
#include "Ball.h"

Ball::Ball() : Shot(), Twilight()
{

}

void Ball::Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position)
{
    Shot::Init(type, path, light, velocity, position);
    Twilight::Init(light, path);
}

//mise a jour
void Ball::Update(float timeFrame)
{
    Shot::Update(timeFrame);
    Twilight::Update(timeFrame);
}

bool Ball::CanCollideWithEntity(Twilight* entity)
{
    return true;
}

int Ball::GetType()
{
    return COLLIDESHOT;
}

SpriteManager* Ball::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f Ball::GetPosition()
{
    return getPosition();
}

void Ball::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}
