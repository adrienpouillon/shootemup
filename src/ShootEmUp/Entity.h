#pragma once

#include <SFML/Graphics.hpp>
#include "SpriteManager.h"

class Scene;

class Entity : public sf::Drawable, public sf::Transformable
{
protected:
	SpriteManager* mSpriteManager;
	int mIsDestroyed;
	sf::Vector2f mVelocity;

public:
	Entity(std::string path, sf::Vector2f velocity, sf::Vector2f position, bool isEntity);

	void Action(float timeFrame);

	virtual void Move(float timeFrame);

	virtual void Attack();

	virtual void Update(float timeFrame);

	bool Collide(std::vector<Entity*> allEntities, int* index);

	virtual void IsCollide(Scene* scene);

	void IsDead();

	void IsExitMap();

	int GetIsDestroyed();

	SpriteManager* GetSpriteManager();

	virtual int GetType() = 0;

	virtual int GetScore();
};