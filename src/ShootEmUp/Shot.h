#pragma once
#include "Twilight.h"
#include "Entity.h"
#include "Scene.h"


class Shot : public Entity
{
protected:
	//type (0 = player,1 = enemie)
	int mType;

public:
	Shot();
	
	virtual void Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position);

	virtual void Update(float timeFrame);

	void IsCollide(Scene* scene, float timeFrame) override;

	virtual void TouchEntity();

	virtual bool CanCollideWithEntity(Twilight* entity) = 0;

	virtual int GetType() = 0;

	int GetMType();

	int GetScore() override;

	virtual SpriteManager* GetSpriteManager() = 0;
};