#include "pch.h"
#include "Player.h"
#include "Enemy.h"
#include "define.h"

#include "Ball.h"
#include "VoltBall.h"
#include "LightBall.h"
#include "ShadowBall.h"
#include "RocBall.h"
#include "MultiBall.h"

#include <iostream>


Player::Player() : Character(), Shooter()
{
    
}

void Player::Init(int up, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position, Text* TextLife)
{
    Character::Init(up, velocity, position);
    Shooter::Init(Scene);
    mCooldownSwap = 0;
    tremble = 1;
    mTextLife = TextLife;//new Text(LIFE, sf::Vector2f(200.f, 30.f), up);
    mTouch = 0;
    ight = light;
}

//deplacer + input
void Player::Move(float timeFrame)
{
    if (mCooldownSwap < TIMEPLAYERSWAP / 2)
    {
        if (mTouch > 0.f)
        {
            Tremor();
        }

        float x = GetPosition().x;
        float y = GetPosition().y;
        //gauche
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {

            x = GetPosition().x - mVelocity.x * timeFrame;// / 20;
            y = GetPosition().y;
            if (x < 0)
            {
                x = GetPosition().x;
            }
        }

        //droite
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            x = GetPosition().x + mVelocity.x * timeFrame*2;//8;//2
            y = GetPosition().y;
            if (x > 1860)
            {
                x = GetPosition().x;
            }
        }

        //haut
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            x = GetPosition().x;
            y = GetPosition().y - mVelocity.y * (timeFrame);// / 20;
            if (y < 60)
            {
                y = GetPosition().y;
            }
        }

        //bas
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            x = GetPosition().x;
            y = GetPosition().y + mVelocity.y * timeFrame * 2;//8;//2
            if (y > 944)
            {
                y = GetPosition().y;
            }
        }

        SetPosition(sf::Vector2f(x, y));
    }
    else
    {
        Tremor();
    }
}

void Player::Tremor()
{
    //tremblement
    float x = GetPosition().x + tremble * 10;
    float y = GetPosition().y;
    if (x < 0)
    {
        x = GetPosition().x;
    }
    if (x > 1860)
    {
        x = GetPosition().x;
    }
    SetPosition(sf::Vector2f(x, y));
    tremble = -tremble;
}


//attaquer + input + verifier si peux attaquer
void Player::Attack()
{
    Entity::Attack();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        CreateBall();
    }
}

//changer de vue
void Player::Swap()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        Shooter::Swap(TIMEPLAYERSWAP, ight);
    }
}

//mise a jour
void Player::Update(float timeFrame)
{
    IsAlive();
    mTextLife->SetValue(mUp);
    Shooter::Update(timeFrame);
    Entity::Update(timeFrame);
    Swap();
}

void Player::IsCollide(Scene* scene, float timeFrame)
{
    //delai d'invincibiliter
    if (mTouch >= 0.f)
    {
        mTouch -= timeFrame;
    }
    bool touch = false;

    std::vector<Shot*> allShot = scene->GetAllEntity<Shot>();
    if (Shot* shot = Collide<Shot*, Player*>(allShot, this))
    {
        if (shot->GetType() >= COLLIDESHOT && shot->GetType() < COLLIDEPLAYER)
        {
            //si pas ne pas toucher
            Twilight* twilight = scene->GetTypeConvert<Twilight*, Shot*>(shot);
            if (CanCollideWithEntity(twilight) == false)
            {
                return;
            }
            if (shot->GetMType() == 1)
            {
                //detruire l'entite toucher
                shot->IsDead();

                //perdre une vie
                touch = true;
            }
        }
    }

    std::vector<Enemy*> allEnemy = scene->GetAllEntity<Enemy>();
    if (Enemy* enemy = Collide<Enemy*, Player*>(allEnemy, this))
    {
        if(enemy->GetType() > COLLIDEPLAYER)
        {
            //detruire l'entite toucher
            enemy->IsDead();

            //perdre une vie
            touch = true;
        }
    }

    if (touch==true)
    {
        //perdre une vie
        TakeDamage();
    }
}

void Player::TakeDamage()
{
    if (mTouch <= 0.f)
    {
        Character::TakeDamage();
    }
    mTouch = 1.f;
}

int Player::GetType()
{
    return COLLIDEPLAYER;
}

int Player::GetScore()
{
    return SCOREPLAYER;
}

int Player::GetDifficulty()
{
    return NODIFFICULTY;
}