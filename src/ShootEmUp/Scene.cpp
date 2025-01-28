#include "pch.h"
#include "Scene.h"
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

//ajouter une scene
void Scene::Add(Entity* entity)
{
	//ajouter une instance a mEntities
	mEntities.push_back(entity);
}

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
		int is = (*it)->GetIsDestroyed();
		if (is == ISDESTROYINGAME)
		{
			IncreaseDifficulty();
			mScore->Increase((*it)->GetScore());
			delete *it;
			it = mEntities.erase(it);
		}
		else if(is == ISDESTROYOUTGAME)
		{
			LowerDifficulty();
			delete* it;
			it = mEntities.erase(it);
		}
		else if(is == ISDESTROYINGAMESHOT)
		{
			mScore->Increase((*it)->GetScore());
			delete* it;
			it = mEntities.erase(it);
		}
		else
		{
			++it;
		}
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

sf::Vector2f Scene::CoordonnateRandomize(sf::Vector2f min, sf::Vector2f max)
{
	sf::Vector2f randomCoordonnee;
	randomCoordonnee.x = GenerateRandomNumber(min.x, max.x);
	randomCoordonnee.y = GenerateRandomNumber(min.y, max.y);
	return randomCoordonnee;
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
			sf::Vector2f coordonate = CoordonnateRandomize(sf::Vector2f(2000, 60), sf::Vector2f(2000, 945));

			//choisir un chiffre environ egale à mDifficulty
			int moreLess = GenerateRandomNumber(0, 3);
			int randomEnemy = GenerateRandomNumber(mDifficulty->GetValue() - moreLess, mDifficulty->GetValue() + moreLess);

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

void Scene::IncreaseDifficulty()
{
	int type = GetTypeScene();
	for (int i = 0; i < DIFFICULTYSCENE; i+= type)
	{
		int rand = GenerateRandomNumber(0, 100);
		if (rand == 5 || rand == 10)
		{
			mDifficulty->Increase(1);
		}
	}
}

void Scene::LowerDifficulty()
{
	int rand = GenerateRandomNumber(0, 100);
	if (rand == 10)
	{
		mDifficulty->Lower(1);
	}
	if (mDifficulty->GetValue() < -1)
	{
		mDifficulty->SetValue(-1);
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
	for (Entity* i : mEntities)
	{
		//afficher
		target.draw(*i);
	}
	for (Text* i : mText)
	{
		target.draw(*i);
	}
}