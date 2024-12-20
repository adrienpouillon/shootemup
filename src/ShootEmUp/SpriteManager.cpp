#include "pch.h"
#include "SpriteManager.h"
#include <iostream>

#define ANIMATIONTIME 0.2

SpriteManager::SpriteManager(std::string path, bool isEntity)
{
    //Load the TileMap at the path
    if (!mTileMap.loadFromFile(path))
    {
        std::cout << "player loading failed";
    }
    mTileMap.setSmooth(false);
    mElapsedTime = 0;

    if(isEntity)
    {
        //Load the first line of the tilemap
        LoadCurrentAnimation(sf::Vector2i(0, 0), sf::Vector2f(mTileMap.getSize().x, 16));

        //Load the first texture of the current animation
        LoadCurrentSprite(sf::Vector2f(16, 16), 0);

        mCurrentSprite.setScale(sf::Vector2f(5.f, 5.f));
        mSize = sf::Vector2f(16, 16);
    }
    else
    {
        //Load the first line of the tilemap
        sf::Vector2f tilemapSize(mTileMap.getSize());
        LoadCurrentAnimation(sf::Vector2i(0, 0), tilemapSize);

        //Load the first texture of the current animation
        LoadCurrentSprite(tilemapSize, 0);

        sf::Vector2f resize(1920 / tilemapSize.x, 1080 / tilemapSize.y);
        mCurrentSprite.setScale(resize);
        mSize = sf::Vector2f(1920, 1080);
    }
    mIsEntity = isEntity;
}

void SpriteManager::LoadCurrentAnimation(sf::Vector2i position, sf::Vector2f size)
{
    sf::Image tmpImage(mTileMap.copyToImage());

    if (!mCurrentAnimation.loadFromImage(tmpImage, sf::IntRect(position, sf::Vector2i(mSize.x, mSize.y))))
    {
        exit(0);  // Si la nouvelle texture ne se charge pas, on quitte
    }

    mFrame = 0;
}

void SpriteManager::LoadCurrentSprite(sf::Vector2f size, float timeFrame)
{
    mCurrentSprite.setTexture(mCurrentAnimation);

    if(mIsEntity)
    {
        mElapsedTime += timeFrame;

        mCurrentSprite.setTextureRect(sf::IntRect(mFrame * 16, 0, mSize.x, mSize.y));

        if(mElapsedTime >= ANIMATIONTIME)
        {
            if (mFrame < 3)
            {
                mFrame++;
            }
            else
            {
                mFrame = 0;
            }
            mElapsedTime -= ANIMATIONTIME;
        }
    }
    else
    {
        mCurrentSprite.setTextureRect(sf::IntRect(0, 0, mSize.x, mSize.y));
    }
    
    
}

sf::Sprite SpriteManager::GetCurrentSprite()
{
    return mCurrentSprite;
}

sf::Vector2f SpriteManager::GetSize()
{
    return mCurrentSprite.getGlobalBounds().getSize();
}

sf::Vector2f SpriteManager::GetPosition()
{
    return mCurrentSprite.getPosition();
}

//Update
void SpriteManager::Update(float timeFrame)
{
    LoadCurrentSprite(mSize, timeFrame);
}
