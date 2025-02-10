#include "pch.h"
#include "Scene.h"
#include "Twilight.h"
#include "Entity.h"
#include <iostream>

#include "Shot.h"
#include "Player.h"
#include "Aureon.h"
#include "Rat.h"
#include "Map.h"
#include "Text.h"

Scene::Scene()
{
	
}

void Scene::Init(float timeGenerate)
{
	mTimeGenerate = timeGenerate;
	mTimeGenerateStay = 0;
	mLight = false;
	mIsFinich = false;
	//mDifficulty->SetValue(17);
}

////ajouter une scene
//void Scene::Add(Entity* entity)
//{
//	//ajouter une instance a mEntities
//	mEntities.push_back(entity);
//}

//ajouter un texte
void Scene::Add(Text* text)
{
	//ajouter une instance a mEntities
	mText.push_back(text);
}

//Mise a jour
void Scene::Update(float timeFrame)
{
	//generer des enemys
	GenerateEnemy(timeFrame);

	for (int i = 0; i < mEntities.size(); ++i)
	{
		//updater
		mEntities[i]->Update(timeFrame);
		mEntities[i]->IsCollide(this, timeFrame);
	}
	//std::cout<< mDifficulty->GetValue() << std::endl;
	//destruction
	for (auto it = mEntities.begin(); it != mEntities.end();)
	{
		DestroyEntity(&it);
	}
	for (Text* i : mText)
	{
		i->Update();
	}
}

int Scene::GenerateRandomNumber(int min, int max)
{
	int range = max - min + 1;
	int value = rand() % range + min;
	return value;
}

sf::Vector2f Scene::ValueRandomize(sf::Vector2f min, sf::Vector2f max)
{
	sf::Vector2f randomValue;
	randomValue.x = (float)GenerateRandomNumber((int)min.x, (int)max.x);
	randomValue.y = (float)GenerateRandomNumber((int)min.y, (int)max.y);
	return randomValue;
}

void Scene::GenerateEnemy(float timeFrame)
{
	mTimeGenerateStay -= timeFrame;
	if (mTimeGenerateStay < 0.f)
	{
		//aleatoire
		//int rand = GenerateRandomNumber(0, 10);//level 1 50 //level 2 200//level 3 1000
		//if (rand == 1)
		//{

			//choisir des coordonnees aleatoire dans l'interval fournie 
			sf::Vector2f coordonate = ValueRandomize(sf::Vector2f(2000, 60), sf::Vector2f(2000, 945));

			//choisir un chiffre environ egale à mDifficulty
			int difficulty = GetText<Difficulty>()->GetValue();
			int moreLess = GenerateRandomNumber(0, 3);
			int randomEnemy = GenerateRandomNumber(difficulty - moreLess, difficulty + moreLess);
			
			//suppression de case -2: et case -1:
			if (randomEnemy < 0)
			{
				randomEnemy = 0;
			}

			//choisi l'enemi en fonction de la difficulter et de la scene
			ChooseEnnemy(coordonate, randomEnemy);
		//}
		mTimeGenerateStay = mTimeGenerate;
	}
}

void Scene::DestroyEntity(auto* it)
{
	int is = (**it)->GetIsDestroyed();
	if (is == ISDESTROYINGAME)
	{
		DestroyInGame(it);
	}
	else if (is == ISDESTROYOUTGAME)
	{
 		DestroyOutGame(it);
	}
	else if (is == ISDESTROYINGAMESHOT)
	{
		DestroyInGameShot(it);
	}
	else if (is == ISDESTROYOUTGAMESHOT)
	{
		DestroyOutGameShot(it);
	}
	else
	{
		++(*it);
	}
}

void Scene::DestroyInGame(auto* it)
{
	IncreaseDifficulty((**it)->GetDifficulty());
	//Score* score = GetText<Score>();
	mScore->Increase((**it)->GetScore());
	delete** it;
	*it = mEntities.erase(*it);
}

void Scene::DestroyInGameShot(auto* it)
{
	//Score* score = GetText<Score>();
	mScore->Increase((**it)->GetScore());
	delete** it;
	*it = mEntities.erase(*it);
}

void Scene::DestroyOutGame(auto* it)
{
	LowerDifficulty((**it)->GetDifficulty());
	LowerDifficulty((**it)->GetDifficulty());
	LowerDifficulty((**it)->GetDifficulty());
	delete** it;
	*it = mEntities.erase(*it);
}

void Scene::DestroyOutGameShot(auto* it)
{
	LowerDifficulty((**it)->GetDifficulty());
	delete** it;
	*it = mEntities.erase(*it);
}

void Scene::IncreaseDifficulty(int probabylity)//50
{
	int type = GetTypeScene();
	for (int i = 0; i < DIFFICULTYSCENE; i+= type)
	{
		int rand = GenerateRandomNumber(0, probabylity);
		if (rand == 1)
		{
			Difficulty* difficulty = GetText<Difficulty>();
			difficulty->Increase(1);
		}
	}
}

void Scene::LowerDifficulty(int probabylity)//100
{
	int rand = GenerateRandomNumber(0, probabylity * 2);
	Difficulty* difficulty = GetText<Difficulty>();
	if (rand == 1)
	{
		difficulty->Lower(1);
	}
	if (difficulty->GetValue() < -1)
	{
		difficulty->SetValue(-1);
	}
}

std::vector<Entity*> Scene::GetEntities()
{
	return mEntities;
}

bool Scene::GetIsFinich()
{
	return mIsFinich;
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	std::vector<Twilight*>twilight = GetAllEntity<Twilight>();
	for (Twilight* i : twilight)
	{
		//afficher
		target.draw(*i);
	}
	std::vector<Text*>text = GetAllText<Text>();
	for (Text* i : text)
	{
		target.draw(*i);
	}
}