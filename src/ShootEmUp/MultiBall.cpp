#include "pch.h"
#include "MultiBall.h"
#include "Scene.h"

MultiBall::MultiBall() : Shot(), Twilight(), Shooter()
{

}

void MultiBall::Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position, Scene* Scene)
{
    Shot::Init(type, path, light, velocity, position);
    Shooter::Init(Scene);
    Twilight::Init(light, path);
    mPath = path;
}

//mise a jour
void MultiBall::Update(float timeFrame)
{
    Shot::Update(timeFrame);
    Twilight::Update(timeFrame);
}

void MultiBall::TouchEntity()
{
    //creer 3 multi-ball
    CreatMultiBall();
    CreatMultiBall();
    CreatMultiBall();

    //se detruire
    IsDead();
}

void MultiBall::CreatMultiBall()
{
    sf::Vector2f min = sf::Vector2f(mVelocity.x - 10.f, mVelocity.y - 100.f);
    sf::Vector2f max = sf::Vector2f(mVelocity.x + 10.f, mVelocity.y + 100.f);
    sf::Vector2f velocity = mScene->ValueRandomize(min, max);
    CreatShot<MultiBall>()->Init(mType, mPath, mLight, velocity, GetPosition(), mScene);
}

bool MultiBall::CanCollideWithEntity(Twilight* entity)
{
    if (GetIsHidden() == entity->GetIsHidden())
    {
        return true;
    }
    return false;
}

SpriteManager* MultiBall::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f MultiBall::GetPosition()
{
    return getPosition();
}

void MultiBall::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}
