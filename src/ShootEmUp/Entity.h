#pragma once

#include <SFML/Graphics.hpp>

class Scene;

class Entity
{
protected:
	int mIsDestroyed;
	sf::Vector2f mVelocity;

public:
	Entity();

	virtual void Init(sf::Vector2f velocity, sf::Vector2f position);

	void Action(float timeFrame);

	virtual void Move(float timeFrame);

	void MoveY();

	virtual void Attack();

	virtual void Update(float timeFrame);

	template<typename T, typename ID>
	T Collide(std::vector<T> allEntities, ID itMe);

	template<typename T, typename ID>
	std::vector<T> CollideAll(std::vector<T> allEntities, ID itMe);

	virtual void IsCollide(Scene* scene, float timeFrame);

	void IsDead();

	void IsExitMap();

	int GetIsDestroyed();

	virtual int GetType() = 0;

	virtual int GetScore();

	virtual int GetDifficulty() = 0;

	virtual sf::Vector2f GetPosition() = 0;

	virtual void SetPosition(sf::Vector2f pos) = 0;

	void SetVelocity(sf::Vector2f velocity);
};

//collision avec un entity
template<typename T, typename ID>
inline T Entity::Collide(std::vector<T> allEntities, ID itMe)
{
	sf::Vector2f position(itMe->GetPosition());
	sf::Vector2f size(itMe->GetSpriteManager()->GetSize());

	for (int i = (int)allEntities.size() - 1; i > 0; i--)
	{
		sf::Vector2f entityPosition = allEntities[i]->GetPosition();
		sf::Vector2f entitySize = allEntities[i]->GetSpriteManager()->GetSize();
		if (allEntities[i] != this)
		{
			if (position.x + size.x >= entityPosition.x && position.x <= entityPosition.x + entitySize.x)
			{
				if (position.y + size.y >= entityPosition.y && position.y <= entityPosition.y + entitySize.y)
				{
					// Les carr�s entrent en collision
					return allEntities[i];
				}
			}
		}
	}
	/*if (position.GetX() + size.GetX() >= colliderPosition.GetX() && position.GetX() <= colliderPosition.GetX() + colliderSize.GetX() &&
		position.GetY() + size.GetY() >= colliderPosition.GetY() && position.GetY() <= colliderPosition.GetY() + colliderSize.GetY())
	{*/
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
					// Les carr�s entrent en collision
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
				// Les carr�s entrent en collision
				(*index) = i;
				return true;
			}
		}
	}*/

	return nullptr;
}

template<typename T, typename ID>
inline std::vector<T> Entity::CollideAll(std::vector<T> allEntities, ID itMe)
{
	std::vector<T> entitiesCollide;
	sf::Vector2f position(itMe->GetPosition());
	sf::Vector2f size(itMe->mSpriteManager->GetSize());

	for (int i = allEntities.size() - 1; i > 0; i--)
	{
		sf::Vector2f entityPosition = allEntities[i]->GetPosition();
		sf::Vector2f entitySize = allEntities[i]->GetSpriteManager()->GetSize();
		if (allEntities[i] != this)
		{
			if (position.x + size.x >= entityPosition.x && position.x <= entityPosition.x + entitySize.x)
			{
				if (position.y + size.y >= entityPosition.y && position.y <= entityPosition.y + entitySize.y)
				{
					// Les carr�s entrent en collision
					entitiesCollide.push_back(allEntities[i]);
				}
			}
		}
	}
	return entitiesCollide;
}


