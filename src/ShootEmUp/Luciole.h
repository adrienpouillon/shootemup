#pragma once
#include "Light.h"
#include "Shooter.h"

class Luciole : public Enemy, public Light, public Shooter
{
protected:

public:
	Luciole();

	void Init(int up, std::string pathLight, std::string pathShadow, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position);

	void Update(float timeFrame);

	void UpdateSprite();

	int GetType();

	bool GetIsHidden();

	int GetScore();

	SpriteManager* GetSpriteManager();

	sf::Vector2f GetPosition();

	void SetPosition(sf::Vector2f pos);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

