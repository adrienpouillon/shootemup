#include "pch.h"
#include "Luciole.h"
#include "define.h"

#include "Ball.h"
#include "VoltBall.h"
#include "LightBall.h"
#include "ShadowBall.h"
#include "RocBall.h"
#include "MultiBall.h"


Luciole::Luciole() : Enemy(), Light(), Shooter()
{

}

void Luciole::Init(int up, std::string pathLight, std::string pathShadow, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position)
{
    Enemy::Init(up, velocity, position);
    Light::Init(light, pathLight);
    Shooter::Init(Scene);

    //creer un 2eme sprite
    Twilight::CreatNewSprite(pathShadow, ISENTITY, SPRITESIZEDEFAULT, SECONDEINDEX);
}

//mise a jour
void Luciole::Update(float timeFrame)
{
    //tirer
    Shooter::Update(timeFrame);
    if (LightBall* lightBall = Shoot<LightBall>(TIMELUCIOLE))
    {
        lightBall->Init(TYPELUCIOLE, BALLLIGHTPATH, mLight, BALLLIGHTVELOCITY, GetPosition());
    }

    //set le bon sprite
    UpdateSprite();

    //fin
    IsAlive();
    Entity::Update(timeFrame);
    Twilight::Update(timeFrame);
}

void Luciole::UpdateSprite()
{
    if (GetIsHidden())
    {
        //sprite Shadow
        mSpriteManager->SetIndex(SECONDEINDEX);
    }
    else
    {
        //sprite Light
        mSpriteManager->SetIndex(FIRSTINDEX);
    }
}

int Luciole::GetType()
{
    return COLLIDEGHOST;
}

bool Luciole::GetIsHidden()
{
    return mIsHidden;
}

int Luciole::GetScore()
{
    return SCOREENEMY * (GHOSTUP + ((int)GHOSTVELOCITYX / 100));
}

SpriteManager* Luciole::GetSpriteManager()
{
    return mSpriteManager;
}

sf::Vector2f Luciole::GetPosition()
{
    return getPosition();
}

void Luciole::SetPosition(sf::Vector2f pos)
{
    return setPosition(pos);
}

void Luciole::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    Twilight::draw(target, states);
}