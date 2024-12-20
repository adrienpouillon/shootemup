#pragma once
#include "Entity.h"


class Map : public Entity
{
public:
	Map(std::string path);

	void Move(float timeFrame);

	//Mise a jour
	void Update(float timeFrame);

	int GetType() override;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

