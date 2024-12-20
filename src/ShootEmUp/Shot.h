#pragma once

#include "Entity.h"
#include "Scene.h"


class Shot : public Entity
{
protected:
	//type (0 = player,1 = enemie)
	int mType;

public:
	Shot(int type, std::string path, sf::Vector2f velocity, sf::Vector2f position);

	void Update(float timeFrame);

	void IsCollide(Scene* scene) override;

	int GetType() override;

	int GetMType();

	int GetScore() override;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};