#pragma once

#include "SceneManager.h"

class GameManager
{
protected:
	static GameManager* mInstance;
	SceneManager mSceneManager;
	sf::RenderWindow mWindow;
public:
	GameManager();

	static GameManager* GetInstance();

	void Run();

	sf::Vector2u GetSize();
};