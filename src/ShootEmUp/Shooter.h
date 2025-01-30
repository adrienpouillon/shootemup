#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "define.h"

//class Scene;

class Shooter
{
protected:
	int mCooldownShoot;
	int mCooldownSwap;
	Scene* mScene;
	float mElapsedTime;

public:
	Shooter();

	virtual void Init(Scene* Scene);

	void Update(float timeFrame);

	template<typename T>
	T* Shoot(int time);

	template<typename T>
	T* CreatShot();

	void Swap(int time, bool* mLight);
};

template<typename T>
inline T* Shooter::CreatShot()
{
	return mScene->Add<T>();
}

//si veux tirer  + si tire
//type (0 = player,1 = enemie)
template<typename T>
inline T* Shooter::Shoot(int time)
{
	if (mCooldownShoot < 0)
	{
		mCooldownShoot = time;
		return CreatShot<T>();
	}
	return nullptr;
}
