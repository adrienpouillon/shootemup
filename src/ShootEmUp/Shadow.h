#pragma once

#include "Enemy.h"

class Shadow : public Enemy
{
protected:
	bool* mLight;
public:
	Shadow();

	virtual void Init(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position);

	void Texturing() override;
};