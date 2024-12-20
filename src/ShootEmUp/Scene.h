#pragma once

#include <SFML/Graphics.hpp>
#include "Text.h"
class Entity;
#include "define.h"
class Score;


class Scene : public sf::Drawable
{
protected:
	//permet le stockage de toute instance affichable et updatable 
	std::vector<Entity*> mEntities;
	bool spawnrandomize;
	Text* mDifficulty;
	Text* mScore;
	bool mLight;
	bool mIsFinich;
public:
	Scene(Text* score);

	void Add(Entity* entity);

	void Update(float timeFrame);

	int GenerateRandomNumber(int min, int max);

	sf::Vector2f CoordonnateRandomize(sf::Vector2f min, sf::Vector2f max);

	virtual void ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy) = 0;

	void GenerateEnemy();

	void IncreaseDifficulty();

	void LowerDifficulty();

	std::vector<Entity*> GetEntities();

	bool GetIsFinich();

	// Hérité via Drawable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};