#include "pch.h"
#include "Entity.h"
#include "Shot.h"
#include "define.h"
#include <iostream>

Entity::Entity()
{
}

void Entity::Init(sf::Vector2f velocity, sf::Vector2f position)
{
	mIsDestroyed = false;
	mVelocity = velocity;
	SetPosition(position);
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
	SetPosition(sf::Vector2f(GetPosition().x - mVelocity.x * timeFrame, GetPosition().y - mVelocity.y * timeFrame));
}

void Entity::MoveY()
{
	if (GetPosition().y > 945 || GetPosition().y < 60)
	{
		mVelocity.y = -mVelocity.y;
	}
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
	if (GetPosition().x < -500 || GetPosition().x > 2520 || GetPosition().y < -500 || GetPosition().y > 1580)
	{
         mIsDestroyed = ISDESTROYOUTGAME;
	}
}

//get/set
int Entity::GetIsDestroyed()
{
	return mIsDestroyed;
}

int Entity::GetScore()
{
	return SCOREDEFAULT;
}

/*int Entity::GetDifficulty()
{
	return NODIFFICULTY;
}*/

void Entity::SetVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}



