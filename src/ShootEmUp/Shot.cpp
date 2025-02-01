#include "pch.h"
#include "Shot.h"
#include "Character.h"
#include "Ghost.h"
#include "define.h"
#include <iostream>

Shot::Shot() : Entity()
{
    
}

void Shot::Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position)
{
    Entity::Init(velocity, position);
    //type (0 = player,1 = enemie)
    mType = type;
}

//mise a jour
void Shot::Update(float timeFrame)
{
    Entity::Update(timeFrame);
}

void Shot::IsCollide(Scene* scene, float timeFrame)
{
    if (mType == 0)
    {
        std::vector<Enemy*> allEnemy = scene->GetAllEntity<Enemy>();
        if (Enemy* enemy = Collide<Enemy*, Shot*>(allEnemy, this))
        {
            //balle creer par le joueur
            if (enemy->GetType() > COLLIDEPLAYER)
            {
                //si pas ne pas toucher
                Twilight* twilight = scene->GetTypeConvert<Twilight*, Enemy*>(enemy);
                if (CanCollideWithEntity(twilight) == false)
                {
                    return;
                }
                //tuer tout les enemies
                //detruire l'entite toucher
                if (enemy->GetType() != COLLIDEGHOST)//(Ghost*)dynamic_cast<Ghost*>(allEntities[index]) == nullptr)
                {
                    ((Character*)enemy)->TakeDamage();
                }
                else
                {
                    if (((Ghost*)enemy)->GetIsHidden())
                    {
                        ((Character*)enemy)->TakeDamage();
                    }
                }
                //se detruire
                TouchEntity();
            }
        }
    }
    else if (mType == 1)
    {
        //balle creer par les enemies
        /*if (allEntities[index]->GetType() == TYPEPLAYER)
        {
          //tuer le joueur
          //detruire l'entite toucher
          ((Character*)allEntities[index])->TakeDamage();
          //se detruire
          IsDead();
        }*/
    }
}

void Shot::TouchEntity()
{
    //se detruire
    IsDead();
}

int Shot::GetMType()
{
    return mType;
}

int Shot::GetScore()
{
    return SCORESHOT * ((int)SHOTVELOCITYX / 200);
}

