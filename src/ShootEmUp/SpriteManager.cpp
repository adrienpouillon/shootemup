#include "pch.h"
#include "SpriteManager.h"
#include "define.h"
#include <iostream>

SpriteManager::SpriteManager()
{

}

int SpriteManager::Init(std::string path, int isEntity, sf::Vector2i size, sf::Vector2i scale)
{
    mTileMap.push_back(sf::Texture());
    mSize.push_back(size);
    if (mSize.size() == mTileMap.size())
    {
        mIndex = mTileMap.size() - 1;
    }
    else
    {
        mIndex++;
    }

    //Load the TileMap at the path
    if (!mTileMap[mIndex].loadFromFile(path))
    {
        std::cout << "player loading failed";
    }
    mTileMap[mIndex].setSmooth(false);
    mElapsedTime = 0;
    

    if(isEntity)
    {
        //Load the first line of the tilemap
        LoadCurrentAnimation(sf::Vector2i(0, 0), sf::Vector2i(mTileMap[mIndex].getSize().x, mSize[mIndex].y));

        //Load the first texture of the current animation
        LoadCurrentSprite(size, 0);

        mCurrentSprite.setScale(scale.x, scale.y);
        
        
    }
    else
    {
        //Load the first line of the tilemap
        sf::Vector2i tilemapSize(mTileMap[mIndex].getSize());
        LoadCurrentAnimation(sf::Vector2i(0, 0), tilemapSize);

        //Load the first texture of the current animation
        LoadCurrentSprite(tilemapSize, 0);

        sf::Vector2f resize(mSize[mIndex].x / tilemapSize.x, mSize[mIndex].y / tilemapSize.y);
        mCurrentSprite.setScale(resize);
        
    }
    mIsEntity = isEntity;
    return mIndex;
}

void SpriteManager::LoadCurrentAnimation(sf::Vector2i position, sf::Vector2i size)
{
    sf::Image tmpImage(mTileMap[mIndex].copyToImage());

    if (!mCurrentAnimation.loadFromImage(tmpImage, sf::IntRect(position, size)))
    {
        exit(1);  // Si la nouvelle texture ne se charge pas, on quitte
    }

    mFrame = 0;
}

void SpriteManager::LoadCurrentSprite(sf::Vector2i size, float timeFrame)
{
    mCurrentSprite.setTexture(mCurrentAnimation);

    if(mIsEntity == 1)
    {
        mElapsedTime += timeFrame;

        mCurrentSprite.setTextureRect(sf::IntRect(mFrame * 16, 0, mSize[mIndex].x, mSize[mIndex].y));

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
        mCurrentSprite.setTextureRect(sf::IntRect(0, 0, mSize[mIndex].x, mSize[mIndex].y));
    }
    
    
}

//Update
void SpriteManager::Update(float timeFrame)
{
    LoadCurrentSprite(mSize[mIndex], timeFrame);
}

sf::Sprite SpriteManager::GetCurrentSprite()
{
    return mCurrentSprite;
}

sf::Vector2f SpriteManager::GetSize()
{
    return mCurrentSprite.getGlobalBounds().getSize();
}

sf::FloatRect SpriteManager::GetCollision()
{
    return mCurrentSprite.getGlobalBounds();
}

sf::Vector2f SpriteManager::GetPosition()
{
    return mCurrentSprite.getPosition();
}

void SpriteManager::SetIndex(int index)
{
    mIndex = index;
    //Load the first line of the tilemap
    LoadCurrentAnimation(sf::Vector2i(0, 0), mSize[mIndex]);
}

int SpriteManager::GetIndex()
{
    return mIndex;
}

