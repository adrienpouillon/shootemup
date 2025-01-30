#pragma once
#include "Shot.h"
#include "Shadow.h"

class ShadowBall :public Shot, public Shadow
{
protected:

public:
	ShadowBall();

	void Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position);

	void Update(float timeFrame);
	
	virtual bool CanCollideWithEntity(Twilight* entity);

	SpriteManager* GetSpriteManager();

	sf::Vector2f GetPosition();

	void SetPosition(sf::Vector2f pos);

};