#pragma once

#include "Character.h"

class Enemy : public Character
{
protected:
	bool mIsHidden;

public:
	Enemy();

	virtual void Init(int up, std::string path, sf::Vector2f velocity, sf::Vector2f position);

	virtual void Texturing() = 0;

	void Move(float timeFrame) override;
};