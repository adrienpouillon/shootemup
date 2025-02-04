#pragma once

#include "Shadow.h"

class Rat : public Enemy, public Shadow
{
protected:

public:
	Rat();

	virtual void Init(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position);

	void Update(float timeFrame) override;

	int GetType() override;

	int GetScore() override;

	SpriteManager* GetSpriteManager();

	sf::Vector2f GetPosition();

	void SetPosition(sf::Vector2f pos);

	virtual int GetDifficulty();

};