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

	bool SwitchI(int i);

	bool SwitchPlusPlus();

	void Add(Scene* scene);

	bool Remove(Scene* scene);

	Scene* Update(float timeFrame);

	Scene* GetCurrentScene();
};

