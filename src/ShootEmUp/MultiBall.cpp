#include "pch.h"
#include "MultiBall.h"
#include "Scene.h"

MultiBall::MultiBall() : Shot(), Twilight(), Shooter()
{

}

void MultiBall::Init(int type, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position, int duplication)
{
    Shot::Init(type, path, light, velocity, position);
    Shooter::Init(Scene);
    Twilight::Init(light, path);
    mPath = path;
    mTimeInvulnerable = 0.15f;
    mDuplication = duplication;
}

//mise a jour
void MultiBall::Update(float timeFrame)
{
    MoveY();
    Shot::Update(timeFrame);
    Twilight::Update(timeFrame);
    mTimeInvulnerable -= timeFrame;
}

void MultiBall::TouchEntity()
{
    if (mTimeInvulnerable < 0.f)
    {
        if (mDuplication > 0)
        {
            //creer 3 multi-ball
            CreatMultiBall();
            CreatMultiBall();
            CreatMultiBall();
        }
        //se detruire
        IsDead();
    }
}

void MultiBall::CreatMultiBall()
{
    sf::Vector2f min = sf::Vector2f(mVelocity.x - 100.f, -mVelocity.y - DUPLICATIONVELOCITY);
    sf::Vector2f max = sf::Vector2f(mVelocity.x + 100.f, mVelocity.y + DUPLICATIONVELOCITY);
    sf::Vector2f velocity = mScene->ValueRandomize(min, max);
    CreatShot<MultiBall>()->Init(mType, mPath, mLight, velocity, mScene, GetPosition(), mDuplication - 1);
}

bool MultiBall::CanCollideWithEntity(Twilight* entity)
{
    if (GetIsHidden() == entity->GetIsHidden())
    {
        return true;
    }
    return false;
}

int MultiBall::GetType()
{
    return COLLIDEMULTIBALL;
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

MultiBall::~MultiBall()
{
    
}
