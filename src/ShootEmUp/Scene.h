#pragma once

#include <SFML/Graphics.hpp>
#include "Score.h"
#include "Difficulty.h"
#include "Up.h"
#include "define.h"

class Entity;


class Scene : public sf::Drawable
{
protected:
	//permet le stockage de toute instance affichable et updatable 
	std::vector<Entity*> mEntities;
	bool spawnrandomize;
	std::vector < Text*> mText;
	Text* mScore;
	Text* mDifficulty;
	Text* mLife;
	bool mLight;
	bool mIsFinich;
	int generateEnemy;
public:
	Scene();

	void Add(Entity* entity);

	void Add(Text* text);

	void Update(float timeFrame);

	int GenerateRandomNumber(int min, int max);

	sf::Vector2f CoordonnateRandomize(sf::Vector2f min, sf::Vector2f max);

	virtual void ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy) = 0;

	void GenerateEnemy();

	void IncreaseDifficulty();

	void LowerDifficulty();

	std::vector<Entity*> GetEntities();

	bool GetIsFinich();

	virtual int GetTypeScene() = 0;

	// Hérité via Drawable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};