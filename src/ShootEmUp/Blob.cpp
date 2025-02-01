#include "pch.h"
#include "Blob.h"

Blob::Blob() : Enemy(), Shadow(), Shooter()
{

}

void Blob::Init(int up, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position)
{
    Enemy::Init(up, velocity, position);
    Shadow::Init(light, path);
    Shooter::Init(Scene);
    mCooldownShoot = TIMEBLOB;
}

void Blob::Update(float timeFrame)
{
    if(mVelocity.x>25.f)
    { 
        //se dupliquer
        Duplicate(timeFrame);
    }

    MoveY();

    //fin
    IsAlive();
    Entity::Update(timeFrame);
    Twilight::Update(timeFrame);
    
}

void Blob::Duplicate(float timeFrame)
{
    //se dupliquer
    Shooter::Update(timeFrame);
    if (Blob* blob = Shoot<Blob>(TIMEBLOB))
    {
        sf::Vector2f min = sf::Vector2f(mVelocity.x - BLOBDUPLICATEVELOCITY.x, -mVelocity.y - BLOBDUPLICATEVELOCITY.y);
        sf::Vector2f max = sf::Vector2f(mVelocity.x + BLOBDUPLICATEVELOCITY.x, mVelocity.y + BLOBDUPLICATEVELOCITY.y);
        sf::Vector2f velocity = mScene->ValueRandomize(min, max);
        blob->Init(BLOBUP, BLOBPATH, mLight, velocity, mScene, GetPosition());
    }
}

int Blob::GetType()
{
    return COLLIDEBLOB;
}

int Blob::GetScore()
{
    return SCOREENEMY * (BLOBUP + ((int)BLOBVELOCITYX / 100));
}

SpriteManager* Blob::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f Blob::GetPosition()
{
    return getPosition();
}

void Blob::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}