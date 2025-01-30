#pragma once
#include "Entity.h"
#include "Twilight.h"


class Map : public Entity, public Twilight
{
public:
	Map();
	
	virtual void Init(sf::Vector2f pos, bool* light, std::string path);

	void Move(float timeFrame);

	//Mise a jour
	void Update(float timeFrame);

	int GetType() override;

	SpriteManager* GetSpriteManager();

	sf::Vector2f GetPosition();

	void SetPosition(sf::Vector2f pos);

};

