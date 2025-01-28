#include "pch.h"
#include "Entity.h"
#include "Shot.h"
#include "define.h"
#include <iostream>

Entity::Entity(std::string path, sf::Vector2f velocity, sf::Vector2f position, bool isEntity)
{
	mIsDestroyed = false;
	mSpriteManager = new SpriteManager(path, isEntity);
	mVelocity = velocity;
	setPosition(position);
}

//Move() + Attack()
void Entity::Action(float timeFrame)
{
	Move(timeFrame);
	Attack();
}

//deplacement de l'entitee
void Entity::Move(float timeFrame)
{
	setPosition(sf::Vector2f(getPosition().x - mVelocity.x * timeFrame, getPosition().y - mVelocity.y * timeFrame));
}

//lancer creer une balle
void Entity::Attack()
{
	return;
}

//Mise a jour
void Entity::Update(float timeFrame)
{
	Action(timeFrame);
	mSpriteManager->Update(timeFrame);
	IsExitMap();
}

//collision avec un entity
bool Entity::Collide(std::vector<Entity*> allEntities, int* index)
{
	/*
	sf::Vector2f position(getPosition());
	sf::Vector2f size(mSpriteManager->GetSize());

	for (int i = allEntities.size() - 1; i > 0; i--)
	{
		sf::Vector2f entityPosition = allEntities[i]->getPosition();
		sf::Vector2f entitySize = allEntities[i]->GetSpriteManager()->GetSize();
		if (allEntities[i] != this)
		{
			if (position.x >= entityPosition.x && position.x < entityPosition.x + entitySize.x)
			{
				if (position.y >= entityPosition.y && position.y < entityPosition.y + entitySize.y)
				{
					// Les carrés entrent en collision
					(*index) = i;
					return true;
				}
			}
		}
	}
	*/
	/*//sf::Vector2f position(getPosition());
	sf::FloatRect rectCollide(mSpriteManager->GetCollision());

	for (int i = allEntities.size() - 1; i > 0; i--)
	{
		//sf::Vector2f entityPosition = allEntities[i]->getPosition();
		sf::FloatRect entityRectCollide(mSpriteManager->GetCollision());
		if (allEntities[i] != this)
		{
			if(rectCollide.intersects(entityRectCollide))
			{
				// Les carrés entrent en collision
				(*index) = i;
				return true;
			}
		}
	}*/
	sf::Vector2f position(getPosition());
	sf::Vector2f size(mSpriteManager->GetSize());

	for (int i = allEntities.size() - 1; i > 0; i--)
	{
		sf::Vector2f entityPosition = allEntities[i]->getPosition();
		sf::Vector2f entitySize = allEntities[i]->GetSpriteManager()->GetSize();
		if (allEntities[i] != this)
		{
			if (position.x + size.x >= entityPosition.x && position.x <= entityPosition.x + entitySize.x)
			{
				if (position.y + size.y >= entityPosition.y && position.y <= entityPosition.y + entitySize.y)
				{
					// Les carrés entrent en collision
					(*index) = i;
					return true;
				}
			}
		}
	}
/*if (position.GetX() + size.GetX() >= colliderPosition.GetX() && position.GetX() <= colliderPosition.GetX() + colliderSize.GetX() &&
	position.GetY() + size.GetY() >= colliderPosition.GetY() && position.GetY() <= colliderPosition.GetY() + colliderSize.GetY())
{*/

	return false;
}

void Entity::IsCollide(Scene* scene)
{

}

//si mort
void Entity::IsDead()
{
	if ((Shot*)dynamic_cast<Shot*>(this)==nullptr)
	{
		mIsDestroyed = ISDESTROYINGAME;
	}
	else
	{
		mIsDestroyed = ISDESTROYINGAMESHOT;
	}
	
}


//si sorti de la map
void Entity::IsExitMap()
{
	if (getPosition().x < -500 || getPosition().x > 2520 || getPosition().y < -500 || getPosition().y > 1580)
	{
         mIsDestroyed = ISDESTROYOUTGAME;
	}
}

//get/set
int Entity::GetIsDestroyed()
{
	return mIsDestroyed;
}

SpriteManager* Entity::GetSpriteManager()
{
	return mSpriteManager;
}

int Entity::GetScore()
{
	return SCOREDEFAULT;
}

void Entity::SetVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}



