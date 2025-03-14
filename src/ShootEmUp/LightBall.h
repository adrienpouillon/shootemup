#pragma once
#include "Ball.h"
#include "Light.h"

class LightBall : public Shot, public Light
{
protected:

public:
	LightBall();

	void Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position);

	void Update(float timeFrame);

	virtual bool CanCollideWithEntity(Twilight* entity);

	virtual int GetType();

	SpriteManager* GetSpriteManager();

	sf::Vector2f GetPosition();

	void SetPosition(sf::Vector2f pos);

};