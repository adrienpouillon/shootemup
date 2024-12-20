#include "pch.h"
#include "Shooter.h"
#include "Scene.h"
#include "Shot.h"
#include <iostream>



Shooter::Shooter(Scene* Scene)
{
    mScene = Scene;
    mCooldownSwap = 0;
    mCooldownShoot = 0;
    mElapsedTime = 0;
}

//mise a jour
void Shooter::Update(float timeFrame)
{
    mElapsedTime += timeFrame;
    if (mElapsedTime >= DECISECONDE)
    {
        mCooldownSwap--;
        mCooldownShoot--;
        mElapsedTime -= DECISECONDE;
    }
}

//si veux tirer  + si tire
//type (0 = player,1 = enemie)
void Shooter::Shoot(int time, int type, sf::Vector2f position)
{
    if (mCooldownShoot < 0)
    {
        if (type == TYPEPLAYER)
        {
            mScene->Add(new Shot(type, SHOTPATH, -SHOTVELOCITY, position));
        }
        else
        {
            mScene->Add(new Shot(type, SHOTPATH, SHOTVELOCITY, position));
        }
        mCooldownShoot = time;
    }
}

void Shooter::Swap(int time, bool* mLight)
{
    if (mCooldownSwap < 0)
    {
        if ((*mLight) == true)
        {
            //mode nuit
            (*mLight) = false;
        }
        else
        {
            //mode jour
            (*mLight) = true;
        }
        mCooldownSwap = time;
    }
}