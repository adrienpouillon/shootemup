#include "pch.h"
#include "Bot.h"

#include "Ball.h"
#include "VoltBall.h"
#include "LightBall.h"
#include "ShadowBall.h"
#include "RocBall.h"
#include "MultiBall.h"

Bot::Bot() : Player(), Twilight()
{

}

void Bot::Init(int up, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position, Text* TextLife)
{
    Twilight::Init(light, path);
    Player::Init(up, light, velocity, Scene, position, TextLife);
}

void Bot::CreateBall()
{
    if (Ball* ball = Shoot<Ball>(TIMEPLAYERSHOOT))
    {
        ball->Init(SHOTTYPEPLAYER, SHOTPATH, mLight, -SHOTVELOCITY, GetPosition());
    }

    /*if (VoltBall* ball = Shoot<VoltBall>(TIMEPLAYERSHOOT))
    {
        ball->Init(SHOTTYPEPLAYER, VOLTBALLPATH, mLight, mScene->ValueRandomize(sf::Vector2f(-(VOLTBALLVELOCITY.x), -(VOLTBALLVELOCITY.y)), sf::Vector2f(-(VOLTBALLVELOCITY.x), -(-VOLTBALLVELOCITY.y))), GetPosition());
    }*/

    /*if (ShadowBall* ball = Shoot<ShadowBall>(TIMEPLAYERSHOOT))
    {
        ball->Init(SHOTTYPEPLAYER, SHADOWBALLPATH, mLight, -SHADOWBALLVELOCITY, GetPosition());
    }*/

    /*if (LightBall* ball = Shoot<LightBall>(TIMEPLAYERSHOOT))
    {
        ball->Init(SHOTTYPEPLAYER, LIGHTBALLPATH, mLight, -LIGHTBALLVELOCITY, GetPosition());
    }*/

    /*if(RocBall * ball = Shoot<RocBall>(TIMEPLAYERSHOOT))
    {
        ball->Init(SHOTTYPEPLAYER, ROCBALLPATH, mLight, -ROCBALLVELOCITY, GetPosition());
    }*/

    /*if (MultiBall* ball = Shoot<MultiBall>(TIMEPLAYERSHOOT))
    {
        ball->Init(SHOTTYPEPLAYER, MULTIBALLPATH, mLight, -MULTIBALLVELOCITY, mScene, GetPosition(), DUPLICATIONMULTIBALL);
    }*/

}

//mise a jour
void Bot::Update(float timeFrame)
{
    IsAlive();
    mTextLife->SetValue(mUp);
    Player::Update(timeFrame);
    Twilight::Update(timeFrame);
    Swap();
}

bool Bot::CanCollideWithEntity(Twilight* entity)
{
    if (GetIsHidden() == entity->GetIsHidden())
    {
        return true;
    }
    return false;
}

SpriteManager* Bot::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f Bot::GetPosition()
{
    return getPosition();
}

void Bot::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}