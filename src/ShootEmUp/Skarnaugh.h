#pragma once
#include "Light.h"
#include "Shooter.h"
#include "Scene.h"

#include "define.h"

class Skarnaugh :public Light, public Shooter
{
protected:

public:
	Skarnaugh(int up, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position);

	void Update(float timeFrame) override;

	int GetType() override;

	int GetScore() override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

