#pragma once

#include "Character.h"
#include "Shooter.h"
#include "Scene.h"
#include "Text.h"




class Player : public Character, public Shooter
{
protected:
	bool* mLight;
	int mTouch;
	int tremble;
	Text* mTextLife;
public:
	Player();
	
	virtual void Init(int up, std::string path, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position, Text* TextLife);

	void Move(float timeFrame) override;

	void Attack() override;

	void Swap();

	void IsCollide(Scene* scene, float timeFrame) override;

	virtual void TakeDamage();

	void Update(float timeFrame) override;

	int GetType() override;

	int GetScore() override;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};