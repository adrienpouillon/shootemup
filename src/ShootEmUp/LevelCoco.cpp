#include "pch.h"
#include "LevelCoco.h"

#include "Ball.h"
#include "VoltBall.h"
#include "LightBall.h"
#include "ShadowBall.h"
#include "RocBall.h"
#include "MultiBall.h"

#include "Bot.h"
#include "Aureon.h"
#include "Rat.h"
#include "Skarnaugh.h"
#include "Ghost.h"
#include "Scarabe.h"
#include "Luciole.h"
#include "Blob.h"
#include "Map.h"

//Boite a outil
//Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, coordonate);
//Add<VoltBall>()->Init(SHOTTYPEENEMY, VOLTBALLPATH, &mLight, VOLTBALLVELOCITY, coordonate);
//Add<VoltBall>()->Init(SHOTTYPEENEMY, VOLTBALLPATH, &mLight, mScene->ValueRandomize(sf::Vector2f(VOLTBALLVELOCITY.x - 10.f, VOLTBALLVELOCITY.y - 100.f), sf::Vector2f(VOLTBALLVELOCITY.x + 10.f, VOLTBALLVELOCITY.y + 100.f), coordonate);
//Add<ShadowBall>()->Init(SHOTTYPEENEMY, SHADOWBALLPATH, &mLight, SHADOWBALLVELOCITY, coordonate);
//Add<LightBall>()->Init(SHOTTYPEENEMY, LIGHTBALLPATH, &mLight, LIGHTBALLVELOCITY, coordonate);
//Add<RocBall>()->Init(SHOTTYPEENEMY, ROCBALLPATH, &mLight, ROCBALLVELOCITY, coordonate);
//Add<MultiBall>()->Init(SHOTTYPEENEMY, MULTIBALLPATH, &mLight, MULTIBALLVELOCITY, this, coordonate, DUPLICATIONMULTIBALL);
// 
//Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
//Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
//Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
//Add<Ghost>()->Init(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, coordonate, TIMEGHOSTHIDDEN);
//Add<Scarabe>()->Init(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate);
//Add<Luciole>()->Init(LUCIOLEUP, LUCIOLEPATHLIGHT, LUCIOLEPATHSHADOW, &mLight, LUCIOLEVELOCITY, this, coordonate);
//Add<Blob>()->Init(BLOBUP, BLOBPATH, &mLight, BLOBVELOCITY, this, coordonate);

LevelCoco::LevelCoco() : Scene()
{

}

void LevelCoco::Init(Text* score, float timeGenerate)
{
    Scene::Init(timeGenerate);

    //texte
    mScore = score;
    //Add<Score>()->Init();
    //mDifficulty = new Difficulty(sf::Vector2f(430.f, 30.f), 0);
    //Add(mDifficulty);
    AddText<Difficulty>()->Init(sf::Vector2f(430.f, 30.f), 0);
    //mLife = new Up(sf::Vector2f(830.f, 30.f), PLAYERUP);
    //Add(mLife);
    Up* lifePlayer = AddText<Up>();
    lifePlayer->Init(sf::Vector2f(830.f, 30.f), PLAYERUP);

    //premiere entity (joueur ou menu)
    Add<Map>()->Init(MAPPOS, &mLight, MAPPATH);
    Add<Map>()->Init(MAPPOS, &mLight, MAPPATH);
    mEntities[1]->SetPosition(sf::Vector2f(1920, 0));
    Add<Bot>()->Init(PLAYERUP, BOTPATH, &mLight, PLAYERVELOCITY, SCENEID, sf::Vector2f(200, 540), lifePlayer);
    mGenerateEnemy = 100;
}

void LevelCoco::ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy)
{
    switch (randomEnemy)
    {
    case -2:
        break;
    case -1:
        break;
    case 0:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 1:
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, coordonate);
        break;
    case 2:
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, coordonate);
        break;
    case 3:
        Add<Ghost>()->Init(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, coordonate, TIMEGHOSTHIDDEN);
        break;
    case 4:
        Add<Ghost>()->Init(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, coordonate, TIMEGHOSTHIDDEN);
        break;
    case 5:
        Add<MultiBall>()->Init(SHOTTYPEENEMY, MULTIBALLPATH, &mLight, sf::Vector2f(MULTIBALLVELOCITYX / 4, MULTIBALLVELOCITYY), this, coordonate, DUPLICATIONMULTIBALL);
        break;
    case 6:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 7:
        Add<Luciole>()->Init(LUCIOLEUP, LUCIOLEPATHLIGHT, LUCIOLEPATHSHADOW, &mLight, LUCIOLEVELOCITY, this, coordonate);
        break;
    case 8:
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, coordonate);
        break;
    case 9:
        Add<Scarabe>()->Init(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate);
        break;
    case 10:
        Add<Scarabe>()->Init(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate);
        break;
    case 11:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 12:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 13:
        Add<Blob>()->Init(BLOBUP, BLOBPATH, &mLight, BLOBVELOCITY, this, coordonate);
        break;
    case 14:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 15:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 16:
        Add<Scarabe>()->Init(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate);
        break;
    case 17:
        Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
        break;
    case 18:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY * 1.5f, coordonate);
        break;
    case 19:
        Add<Luciole>()->Init(LUCIOLEUP, LUCIOLEPATHLIGHT, LUCIOLEPATHSHADOW, &mLight, LUCIOLEVELOCITY, this, coordonate);
        break;
    case 20:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 40.f));
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y + 40.f));
        break;
    case 21:
        Add<Scarabe>()->Init(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate);
        break;
    case 22:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 23:
        Add<Scarabe>()->Init(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate);
        break;
    case 24:
        Add<Luciole>()->Init(LUCIOLEUP, LUCIOLEPATHLIGHT, LUCIOLEPATHSHADOW, &mLight, LUCIOLEVELOCITY, this, coordonate);
        break;
    case 25:
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, coordonate);
        break;
    case 26:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 27:
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, coordonate);
        break;
    case 28:
        Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
        break;
    case 29:
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, coordonate);
        break;
    case 30:
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, coordonate);
        break;
    case 31:
        Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
        break;
    case 32:
        Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
        break;
    case 33:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY * 1.5f, coordonate);
        break;
    case 34:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY * 1.5f, coordonate);
        break;
    case 35:
        Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
        break;
    case 36:
        Add<Scarabe>()->Init(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate);
        break;
    case 37:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 38:
        Add<Scarabe>()->Init(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate);
        break;
    case 39:
        Add<Ghost>()->Init(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, coordonate, TIMEGHOSTHIDDEN);
        break;
    case 40:
        Add<Ghost>()->Init(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, coordonate, TIMEGHOSTHIDDEN);
        break;
    case 41:
        Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
        break;
    case 42:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 43:
        Add<Ghost>()->Init(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, coordonate, TIMEGHOSTHIDDEN);
        break;
    case 44:
        Add<Scarabe>()->Init(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate);
        break;
    case 45:
        Add<Blob>()->Init(BLOBUP, BLOBPATH, &mLight, BLOBVELOCITY, this, coordonate);
        break;
    case 46:
        Add<Ghost>()->Init(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 40.f), TIMEGHOSTHIDDEN);
        Add<Ghost>()->Init(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y), TIMEGHOSTHIDDEN);
        Add<Ghost>()->Init(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y + 40.f), TIMEGHOSTHIDDEN);
        break;
    case 47:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, sf::Vector2f(coordonate.x, coordonate.y - 40.f));
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, sf::Vector2f(coordonate.x, coordonate.y));
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, sf::Vector2f(coordonate.x, coordonate.y + 40.f));
        break;
    case 48:
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 40.f));
        Add<Ball>()->Init(SHOTTYPEENEMY, SHOTPATH, &mLight, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y + 40.f));
        break;
    case 49:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY * 3.f, sf::Vector2f(coordonate.x, coordonate.y - 40.f));
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY * 3.f, sf::Vector2f(coordonate.x, coordonate.y));
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY * 3.f, sf::Vector2f(coordonate.x, coordonate.y + 40.f));
        break;
    case 50:
        Add<Ghost>()->Init(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY * 2.f, coordonate, TIMEGHOSTHIDDEN);
        break;
    }
    Difficulty* difficulty = GetText<Difficulty>();
    if (difficulty->GetValue() > 52)
    {
        mIsFinich = true;
    }
}

int LevelCoco::GetTypeScene()
{
    return LEVEL1;
}
