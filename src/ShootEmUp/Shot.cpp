#include "pch.h"
#include "Shot.h"
#include "Character.h"
#include "Ghost.h"
#include <iostream>

Shot::Shot() : Entity()
{
    
}

void Shot::Init(int type, std::string path, sf::Vector2f velocity, sf::Vector2f position)
{
    Entity::Init(path, velocity, position, 1);
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
                IsDead();
            }



            /*//balle creer par le joueur
            if (allEntities[index]->GetType() > COLLIDEPLAYER)
            {
                //tuer tout les enemies
                //detruire l'entite toucher
                if (allEntities[index]->GetType() != COLLIDEGHOST)//(Ghost*)dynamic_cast<Ghost*>(allEntities[index]) == nullptr)
                {
                    ((Character*)allEntities[index])->TakeDamage();
                }
                else
                {
                    if (((Ghost*)allEntities[index])->GetIsHidden())
                    {
                        ((Character*)allEntities[index])->TakeDamage();
                    }
                }
                //se detruire
                IsDead();
            }*/
        
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
    else if (mType == 1)
    {

    }
}

int Shot::GetType()
{
    return COLLIDESHOT;
}

int Shot::GetMType()
{
    return mType;
}

int Shot::GetScore()
{
    return SCORESHOT * ((int)SHOTVELOCITYX / 200);
}



void Shot::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());
    target.draw(mSpriteManager->GetCurrentSprite(), states);
}