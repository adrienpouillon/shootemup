#pragma once
#include "Light.h"
#include "Shooter.h"
#include "Scene.h"

#include "define.h"

class Skarnaugh :public Enemy, public Light, public Shooter
{
protected:

public:
	Skarnaugh();

	virtual void Init(int up, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position);

	void Update(float timeFrame) override;

	int GetType() override;

	int GetScore() override;

	SpriteManager* GetSpriteManager();

	sf::Vector2f GetPosition();

	void SetPosition(sf::Vector2f pos);

};

