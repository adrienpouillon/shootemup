#include "pch.h"
#include "SceneManager.h"
#include "LevelCoco.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Text.h"
#include "define.h"
#include <iostream>


SceneManager::SceneManager()
{

}

void SceneManager::Init()
{
	//initialiser mScenes

	//scene menu
	Text* score = new Score(sf::Vector2f(30.f,30.f), 0);
	Add<LevelCoco>()->Init(score, 0.37f);
	Add<Level1>()->Init(score, 0.37f);
	Add<Level2>()->Init(score, 0.17f);
	Add<Level3>()->Init(score, 0.037f);

	NbScene = 3;

	//definir la scene actif
	mCurrentScene = mScenes[0];
}

//echange 2 scenes
bool SceneManager::SwitchI(int i)
{
	bool execution = false;
	int lenght = (int)mScenes.size();
	if(i > lenght - 1 || i < 0)
	{
		mCurrentScene = mScenes[i];
	}
	return execution;
}

bool SceneManager::SwitchScenePlusPlus()
{
	bool execution = false;
	int lenght = (int)mScenes.size();
	for (int i = 0; i < lenght; i++)
	{
		if (mCurrentScene == mScenes[i])
		{
			if (i + 1 < lenght)
			{
				mCurrentScene = mScenes[i + 1];
				execution = true;
			}
			break;
		}
	}
	return execution;
}

//ajoute une scene
void SceneManager::Add(Scene* scene)
{
	//ajouter une instance a mScenes
	mScenes.push_back(scene);
}

//supprime une scene
bool SceneManager::Remove(Scene* scene)
{
	//supprimer une instance de mScenes
	bool execution = false;
	int lenght = (int)mScenes.size();
	for (int i = 0; i < lenght; i++)
	{
		if (scene == mScenes[i])
		{
			execution = true;
			SwitchScenePlusPlus();
			mScenes.erase(mScenes.begin() + i);
			delete scene;
			break;
		}
	}
	return execution;
}

//Mise a jour
Scene* SceneManager::Update(float timeFrame)
{
	mCurrentScene->Update(timeFrame);
	//si fini
	if (mCurrentScene->GetIsFinich() == true)
	{
		for (int i = 0; i < mScenes.size(); i++)
		{
			if (mCurrentScene == mScenes[i])
			{
				if (i > NbScene)
				{
					std::cout << "Merci d'avoir joue' !!!" << std::endl;
					exit(0);
				}
				else
				{
					SwitchScenePlusPlus();
				}
			}
		}
	}
	return mCurrentScene;
}

Scene* SceneManager::GetCurrentScene()
{
	return mCurrentScene;
}
