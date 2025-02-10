#include "pch.h"
#include "GameManager.h"
#include "define.h"
#include <iostream>

GameManager* GameManager::mInstance = nullptr;

GameManager::GameManager()
{
    if (mInstance == nullptr)
        mInstance = this;
}

GameManager* GameManager::GetInstance()
{
    if (mInstance == nullptr)
    {
        mInstance = new GameManager();
    }
    return mInstance;
}

void GameManager::Init()
{
    mWindow.create(sf::VideoMode(SIZEWINDOWX, SIZEWINDOWY), "Shoot'Em Up works!");//, sf::Style::Fullscreen)
    mSceneManager = new SceneManager();
    mSceneManager->Init();
}

//boucle SFML
void GameManager::Run()
{
    sf::Clock clock;
    //  //code
    while (mWindow.isOpen())
    {
        sf::Time elapsed = clock.restart();

        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                mWindow.close();
                break;
            }
        }

        mWindow.clear();
        //draw


        Scene* s = mSceneManager->Update(elapsed.asSeconds());

        mWindow.draw(*s);

        mWindow.display();
    }
}

sf::Vector2u GameManager::GetSize()
{
    return mWindow.getSize();
}

GameManager::~GameManager()
{
    delete mSceneManager;
}
