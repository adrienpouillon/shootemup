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
    if (MultiBall* ball = Shoot<MultiBall>(TIMEPLAYERSHOOT))//VoltBall ShadowBall LightBall RocBall MultiBall
    {
        //ball->Init(SHOTTYPEPLAYER, SHOTPATH, mLight, -SHOTVELOCITY, GetPosition());
        //ball->Init(SHOTTYPEPLAYER, VOLTBALLPATH, mLight, mScene->ValueRandomize(sf::Vector2f(-(VOLTBALLVELOCITY.x), -(VOLTBALLVELOCITY.y)), sf::Vector2f(-(VOLTBALLVELOCITY.x), -(-VOLTBALLVELOCITY.y))), GetPosition());
        //ball->Init(SHOTTYPEPLAYER, SHADOWBALLPATH, mLight, -SHADOWBALLVELOCITY, GetPosition());
        //ball->Init(SHOTTYPEPLAYER, LIGHTBALLPATH, mLight, -LIGHTBALLVELOCITY, GetPosition());
        //ball->Init(SHOTTYPEPLAYER, ROCBALLPATH, mLight, -ROCBALLVELOCITY, GetPosition());
        ball->Init(SHOTTYPEPLAYER, MULTIBALLPATH, mLight, -MULTIBALLVELOCITY, mScene, GetPosition(), DUPLICATIONMULTIBALL);
    }
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