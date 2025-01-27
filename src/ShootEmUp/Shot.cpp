#include "pch.h"
#include "Shot.h"
#include "Character.h"
#include "Ghost.h"
#include <iostream>

Shot::Shot(int type, std::string path, sf::Vector2f velocity, sf::Vector2f position) : Entity(path, velocity, position, 1)
{
    //type (0 = player,1 = enemie)
    mType = type;
}

//mise a jour
void Shot::Update(float timeFrame)
{
    Entity::Update(timeFrame);
}

void Shot::IsCollide(Scene* scene)
{
    int index = 0;
    std::vector<Entity*> allEntities = scene->GetEntities();
    if (Collide(allEntities, &index) == true)
    {
        if (mType == 0)
        {
            //balle creer par le joueur
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
            }
        }
        else if(mType == 1)
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