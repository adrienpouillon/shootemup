#pragma once
#include "Shadow.h"
#include "Shooter.h"
#include "define.h"

class Blob : public Enemy, public Shadow, public Shooter
{
protected:

public:
	Blob();

	virtual void Init(int up, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position);

	void Update(float timeFrame);

	void Duplicate(float timeFrame);

	void CreateBlob();

	int GetType();

	int GetScore();

	SpriteManager* GetSpriteManager();

	sf::Vector2f GetPosition();

	void SetPosition(sf::Vector2f pos);
};

