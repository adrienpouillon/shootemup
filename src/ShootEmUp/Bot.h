#pragma once
#include "Player.h"

class Bot : public Player, public Twilight
{
protected:

public:
	Bot();

	void Init(int up, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position, Text* TextLife);

	virtual void CreateBall();

	void Update(float timeFrame);

	virtual bool CanCollideWithEntity(Twilight* entity);

	SpriteManager* GetSpriteManager();

	sf::Vector2f GetPosition();

	void SetPosition(sf::Vector2f pos);

};

