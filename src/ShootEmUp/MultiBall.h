#pragma once
#include "Shot.h"
#include "Shooter.h"
#include "Twilight.h"

class MultiBall :public Shot, public Twilight, public Shooter
{
protected:
	std::string mPath;
public:
	MultiBall();

	void Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position, Scene* Scene);

	void Update(float timeFrame);

	void TouchEntity();

	void CreatMultiBall();

	virtual bool CanCollideWithEntity(Twilight* entity);

	SpriteManager* GetSpriteManager();

	sf::Vector2f GetPosition();

	void SetPosition(sf::Vector2f pos);

};