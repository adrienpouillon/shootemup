#include "pch.h"
#include "Level3.h"

#include "Ball.h"
#include "VoltBall.h"
#include "LightBall.h"
#include "ShadowBall.h"
#include "RocBall.h"
#include "MultiBall.h"
#include "Bot.h"
#include "Player.h"
#include "Aureon.h"
#include "Rat.h"
#include "Skarnaugh.h"
#include "Ghost.h"
#include "Scarabe.h"
#include "Map.h"

//Boite a outil
//Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, coordonate);
//Add<VoltBall>()->Init(SHOTTYPEENEMY, VOLTBALLPATH, &mLight, VOLTBALLVELOCITY, coordonate);
//Add<VoltBall>()->Init(SHOTTYPEENEMY, VOLTBALLPATH, &mLight, mScene->ValueRandomize(sf::Vector2f(VOLTBALLVELOCITY.x - 10.f, VOLTBALLVELOCITY.y - 100.f), sf::Vector2f(VOLTBALLVELOCITY.x + 10.f, VOLTBALLVELOCITY.y + 100.f), coordonate);
//Add<ShadowBall>()->Init(SHOTTYPEENEMY, SHADOWBALLPATH, &mLight, SHADOWBALLVELOCITY, coordonate);
//Add<LightBall>()->Init(SHOTTYPEENEMY, LIGHTBALLPATH, &mLight, LIGHTBALLVELOCITY, coordonate);
//Add<RocBall>()->Init(SHOTTYPEENEMY, ROCBALLPATH, &mLight, ROCBALLVELOCITY, coordonate);
//Add<MultiBall>()->Init(SHOTTYPEENEMY, MULTIBALLPATH, &mLight, MULTIBALLVELOCITY, this, coordonate);
// 
//Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
//Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
//Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
//Add<Ghost>()->Init(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, coordonate, TIMEGHOSTHIDDEN);
//Add<Scarabe>()->Init(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate);
//Add<Luciole>()->Init(LUCIOLEUP, LUCIOLEPATHLIGHT, LUCIOLEPATHSHADOW, &mLight, LUCIOLEVELOCITY, this, coordonate);

Level3::Level3() : Scene()
{
    
}

void Level3::Init(Text* score, float timeGenerate)
{
    Scene::Init(timeGenerate);

    //texte
    mScore = score;
    Add(score);
    //mDifficulty = new Difficulty(sf::Vector2f(430.f, 30.f), 0);
    //Add(mDifficulty);
    AddText<Difficulty>()->Init(sf::Vector2f(430.f, 30.f), 0);
    //mLife = new Up(sf::Vector2f(830.f, 30.f), PLAYERUP);
    //Add(mLife);
    Up* lifePlayer = AddText<Up>();
    lifePlayer->Init(sf::Vector2f(830.f, 30.f), PLAYERUP);

    //premiere entity (joueur ou menu)
    //Add<Map>()->Init(MAPPOS, &mLight, MAPPATH);
    //Add<Map>()->Init(MAPPOS, &mLight, MAPPATH);
    //mEntities[1]->SetPosition(sf::Vector2f(1920, 0));
    Add<Bot>()->Init(PLAYERUP * 5, BOTPATH, &mLight, PLAYERVELOCITY, SCENEID, sf::Vector2f(200, 540), lifePlayer);
    mGenerateEnemy = 1000;
}

void Level3::ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy)
{
    switch (randomEnemy)
    {
    case -2:
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 80.f));
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y));
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y + 80.f));
        break;
    case -1:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 0:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 40.f));
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y + 40.f));
        break;
    case 1:
        Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
        break;
    case 2:
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, coordonate);
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 3:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 40.f));
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, sf::Vector2f(coordonate.x, coordonate.y + 40.f));
        break;
    case 4:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY * 2.f, this, coordonate);
        break;
    case 5:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, sf::Vector2f(coordonate.x + 80.f, coordonate.y));
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, sf::Vector2f(coordonate.x, coordonate.y));
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, sf::Vector2f(coordonate.x - 80.f, coordonate.y));
        break;
    case 6:
        Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
        break;
    case 7:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x + 80.f, coordonate.y));
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y));
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x - 80.f, coordonate.y));
        break;
    case 8:
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 40.f));
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y + 40.f));
        break;
    case 9:
        Add<Rat>()->Init(RATUP*2, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 10:
        Add<Aureon>()->Init(AUREONUP*2, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 11:
        Add<Aureon>()->Init(AUREONUP*2, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 12:
        Add<Ball>()->Init(SHOTTYPEENEMY / 2, SHOTPATH, &mLight, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 80.f));
        Add<Ball>()->Init(SHOTTYPEENEMY / 2, SHOTPATH, &mLight, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y));
        Add<Ball>()->Init(SHOTTYPEENEMY / 2, SHOTPATH, &mLight, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y + 80.f));
        break;
    case 13:
        Add<Aureon>()->Init(AUREONUP*2, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 14:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY * 1.5f, coordonate);
        break;
    case 15:
        Add<Rat>()->Init(RATUP*2, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 16:
        Add<Aureon>()->Init(AUREONUP*2, AUREONPATH, &mLight, AUREONVELOCITY, this, sf::Vector2f(coordonate.x, coordonate.y - 40.f));
        Add<Aureon>()->Init(AUREONUP*2, AUREONPATH, &mLight, AUREONVELOCITY, this, sf::Vector2f(coordonate.x, coordonate.y + 40.f));
        break;
    case 17:
        Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY * 1.5f, this, coordonate);
        break;
    case 18:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY * 1.5f, this, coordonate);
        break;
    case 19:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY * 1.5f, coordonate);
        break;
    case 20:
        Add<Rat>()->Init(RATUP*3, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 40.f));
        Add<Rat>()->Init(RATUP*3, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y + 40.f));
        break;
    case 21:

        break;
    }
    Difficulty* difficulty = GetText<Difficulty>();
    if (difficulty->GetValue() > 52)
    {
        mIsFinich = true;
    }
}

int Level3::GetTypeScene()
{
    return LEVEL3;
}