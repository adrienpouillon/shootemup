#include "pch.h"
#include "Entity.h"
#include "Shot.h"
#include "define.h"
#include <iostream>

Entity::Entity()
{
}

void Entity::Init(std::string path, sf::Vector2f velocity, sf::Vector2f position, bool isEntity)
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

void Entity::IsCollide(Scene* scene, float timeFrame)
{

}

//si mort
void Entity::IsDead()
{
	if (dynamic_cast<Shot*>(this)==nullptr)
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



