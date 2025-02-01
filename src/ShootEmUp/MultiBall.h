#pragma once
#include "Shot.h"
#include "Shooter.h"
#include "Twilight.h"

class MultiBall :public Shot, public Twilight, public Shooter
{
protected:
	std::string mPath;
	float mTimeInvulnerable;
	int mDuplication;
public:
	MultiBall();

	void Init(int type, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position, int duplication);

	void Update(float timeFrame);

	void TouchEntity();

	void CreatMultiBall();

	virtual bool CanCollideWithEntity(Twilight* entity);

	virtual int GetType();

	SpriteManager* GetSpriteManager();

	sf::Vector2f GetPosition();

	void SetPosition(sf::Vector2f pos);

	~MultiBall();

};