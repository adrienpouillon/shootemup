#include "pch.h"
#include "Player.h"
#include "Shot.h"
#include <iostream>
#include "define.h"

Player::Player(int up, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position) : Character(up, path, velocity, position), Shooter(Scene)
{
    mCooldownSwap = 0;
    mLight = light;
    tremble = 1;
    mTextLife = new Text(LIFE, sf::Vector2f(200.f, 30.f), up);
}

//deplacer + input
void Player::Move(float timeFrame)
{
    if (mCooldownSwap < TIMEPLAYERSWAP / 2)
    {
        int x = getPosition().x;
        int y = getPosition().y;
        //gauche
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {

            x = getPosition().x - mVelocity.x * timeFrame;
            y = getPosition().y;
            if (x < 0)
            {
                x = getPosition().x;
            }
        }

        //droite
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            x = getPosition().x + mVelocity.x * timeFrame*5;
            y = getPosition().y;
            if (x > 1860)
            {
                x = getPosition().x;
            }
        }

        //haut
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            x = getPosition().x;
            y = getPosition().y - mVelocity.y * (timeFrame-0.00030);
            if (y < 60)
            {
                y = getPosition().y;
            }
        }

        //bas
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            x = getPosition().x;
            y = getPosition().y + mVelocity.y *timeFrame*5;
            if (y > 944)
            {
                y = getPosition().y;
            }
        }

        setPosition(sf::Vector2f(x, y));
    }
    else
    {
        //tremblement
        int x = getPosition().x + tremble * 10;
        int y = getPosition().y;
        if (x < 0)
        {
            x = getPosition().x;
        }
        if (x > 1860)
        {
            x = getPosition().x;
        }
        setPosition(sf::Vector2f(x, y));
        tremble = -tremble;
    }
}
//attaquer + input + verifier si peux attaquer
void Player::Attack()
{
    Entity::Attack();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Shooter::Shoot(TIMEPLAYERSHOOT, TYPEPLAYER, getPosition());
    }
}

//changer de vue
void Player::Swap()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        Shooter::Swap(TIMEPLAYERSWAP, mLight);
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

void Player::IsCollide(Scene* scene)
{
    int index = 0;
    std::vector<Entity*> allEntities = scene->GetEntities();
    if (Collide(allEntities, &index) == true)
    {
        if (allEntities[index]->GetType() == COLLIDESHOT)
        {
            if (((Shot*)allEntities[index])->GetMType() == 1)
            {
                std::cout << allEntities[index]->GetType();
                //detruire l'entite toucher
                allEntities[index]->IsDead();

                //perdre une vie
                TakeDamage();
            }
        }
        else if(allEntities[index]->GetType() > COLLIDEPLAYER)
        {
            std::cout << allEntities[index]->GetType();
            //detruire l'entite toucher
            allEntities[index]->IsDead();

            //perdre une vie
            TakeDamage();
        }

    }
}

int Player::GetType()
{
    return COLLIDEPLAYER;
}

int Player::GetScore()
{
    return SCOREPLAYER;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());
	target.draw(mSpriteManager->GetCurrentSprite(), states);
}