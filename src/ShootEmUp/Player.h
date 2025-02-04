#pragma once
#include "Twilight.h"
#include "Character.h"
#include "Shooter.h"
#include "Scene.h"
#include "Text.h"




class Player : public Character, public Shooter
{
protected:
	bool* ight;
	float mTouch;
	int tremble;
	Text* mTextLife;
public:
	Player();
	
	virtual void Init(int up, bool* light, sf::Vector2f velocity, Scene* Scene, sf::Vector2f position, Text* TextLife);

	void Move(float timeFrame) override;

	void Tremor();

	void Attack() override;

	virtual void CreateBall() = 0;

	void Swap();

	void IsCollide(Scene* scene, float timeFrame) override;

	virtual void TakeDamage();

	virtual bool CanCollideWithEntity(Twilight* entity) = 0;

	void Update(float timeFrame) override;

	int GetType() override;

	int GetScore() override;

	virtual int GetDifficulty();

	virtual SpriteManager* GetSpriteManager() = 0;

	virtual sf::Vector2f GetPosition() = 0;

	virtual void SetPosition(sf::Vector2f pos) = 0;

};