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
	int mGenerateEnemy;
	float mTimeGenerate;
	float mTimeGenerateStay;
public:
	Scene();
	
	virtual void Init(float timeGenerate);

	void Add(Entity* entity);

	template <typename T>
	T* Add();

	void Add(Text* text);

	void Update(float timeFrame);

	int GenerateRandomNumber(int min, int max);

	sf::Vector2f CoordonnateRandomize(sf::Vector2f min, sf::Vector2f max);

	virtual void ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy) = 0;

	void GenerateEnemy(float timeFrame);

	void IncreaseDifficulty();

	void LowerDifficulty();

	std::vector<Entity*> GetEntities();

	bool GetIsFinich();

	virtual int GetTypeScene() = 0;

	template<typename T>
	T* GetEntity();

	template<typename T>
	std::vector<T*> GetAllEntity();

	template<typename T>
	T* GetText();

	template<typename T>
	std::vector<T*> GetAllText();

	// H�rit� via Drawable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

template<typename T>
inline T* Scene::Add()
{
	T* t = new T();
	mEntities.push_back(t);
	return t;
}

template<typename T>
inline T* Scene::GetEntity()
{
	for (int i = 0; i < mEntities.size(); ++i)
	{
		if (T* entity = dynamic_cast<T*>(mEntities))
		{
			return entity;
		}
	}
	return nullptr;
}

template<typename T>
inline std::vector<T*> Scene::GetAllEntity()
{
	std::vector<T*> allT;
	for (int i = 0; i < mEntities.size(); ++i)
	{
		if (T* entity = dynamic_cast<T*>(mEntities[i]))
		{
			allT.push_back(entity);
		}
	}
	return allT;
}

template<typename T>
inline T* Scene::GetText()
{
	for (int i = 0; i < mText.size(); ++i)
	{
		if (T* text = dynamic_cast<T*>(mEntities))
		{
			return text;
		}
	}
	return nullptr;
}

template<typename T>
inline std::vector<T*> Scene::GetAllText()
{
	std::vector<T*> allT;
	for (int i = 0; i < mText.size(); ++i)
	{
		if (T* text = dynamic_cast<T*>(mText[i]))
		{
			allT.push_back(text);
		}
	}
	return allT;
}
