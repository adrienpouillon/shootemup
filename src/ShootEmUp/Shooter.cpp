#include "pch.h"
#include "Shooter.h"
#include "Scene.h"

#include "Ball.h"
#include "VoltBall.h"
#include "LightBall.h"
#include "ShadowBall.h"
#include "RocBall.h"
#include "MultiBall.h"



Shooter::Shooter()
{
    
}

void Shooter::Init(Scene* Scene)
{
    mScene = Scene;
    mCooldownSwap = 0;
    mCooldownShoot = 0;
    mElapsedTime = 0;
}

//mise a jour pour charger le tire
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