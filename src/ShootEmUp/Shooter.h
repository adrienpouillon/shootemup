#pragma once

#include <SFML/Graphics.hpp>

#include "define.h"

class Scene;

class Shooter
{
protected:
	int mCooldownShoot;
	int mCooldownSwap;
	Scene* mScene;
	float mElapsedTime;

public:
	Shooter(Scene* Scene);

	void Update(float timeFrame);

	void Shoot(int time, int type, sf::Vector2f position);

	void Swap(int time, bool* mLight);
};