#pragma once
#include "Scene.h"

class SceneManager
{
protected:
	std::vector <Scene*> mScenes;
	//tableau //0 = menu //1 = level 1 //2 = level 2 //...
	Scene* mCurrentScene;
	int NbScene;
public:
	SceneManager();

	void Init();

	bool SwitchI(int i);

	bool SwitchScenePlusPlus();

	void Add(Scene* scene);

	template <typename T>
	T* Add();

	template<typename T>
	T* GetScene();

	template<typename T>
	T* GetAllScene();

	bool Remove(Scene* scene);

	Scene* Update(float timeFrame);

	Scene* GetCurrentScene();
};

template<typename T>
inline T* SceneManager::Add()
{
	T* t = new T();
	mScenes.push_back(t);
	return t;
}

template<typename T>
inline T* SceneManager::GetScene()
{
	for (int i = 0; i < mScenes.size(); ++i)
	{
		if (T* entity = dynamic_cast<T*>(mScenes))
		{
			return entity;
		}
	}
	return nullptr;
}

template<typename T>
inline T* SceneManager::GetAllScene()
{
	std::vector<T*> allT;
	for (int i = 0; i < mScenes.size(); ++i)
	{
		if (T* entity = dynamic_cast<T*>(mScenes))
		{
			allT.push_back(entity);
		}
	}
	return allT;
}

