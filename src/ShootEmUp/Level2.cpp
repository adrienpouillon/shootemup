#include "pch.h"
#include "Level2.h"

#include "Shot.h"
#include "Player.h"
#include "Aureon.h"
#include "Rat.h"
#include "Skarnaugh.h"
#include "Ghost.h"
#include "Scarabe.h"
#include "Map.h"

//Boite a outil
//Add<Shot>()->Init(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, coordonate);
//Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
//Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
//Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
//Add<Ghost>()->Init(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, coordonate, TIMEGHOSTHIDDEN);
//Add<Scarabe>()->Init(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate);
//


Level2::Level2() : Scene()
{
    
}

void Level2::Init(Text* score, float timeGenerate)
{
    Scene::Init(timeGenerate);

    //texte
    mScore = score;
    Add(score);
    mDifficulty = new Difficulty(sf::Vector2f(430.f, 30.f), 0);
    Add(mDifficulty);
    mLife = new Up(sf::Vector2f(830.f, 30.f), PLAYERUP);
    Add(mLife);

    //premiere entity (joueur ou menu)
    Add<Map>()->Init(MAPPATH);
    Add<Map>()->Init(MAPPATH);
    mEntities[1]->setPosition(sf::Vector2f(1920, 0));
    Add<Player>()->Init(PLAYERUP * 3, PLAYERPATH, &mLight, PLAYERVELOCITY, SCENEID, sf::Vector2f(200, 540), mLife);
    mGenerateEnemy = 200;
}

void Level2::ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy)
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
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 2:
        Add<Shot>()->Init(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, coordonate);
        break;
    case 3:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 4:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 5:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 6:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 7:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 8:
        Add<Shot>()->Init(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, coordonate);
        break;
    case 9:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 10:
        Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
        break;
    case 11:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 12:
        Add<Shot>()->Init(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 80.f));
        Add<Shot>()->Init(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y));
        Add<Shot>()->Init(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y + 80.f));
        break;
    case 13:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 14:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY * 1.5f, coordonate);
        break;
    case 15:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 16:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, sf::Vector2f(coordonate.x, coordonate.y - 40.f));
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, sf::Vector2f(coordonate.x, coordonate.y + 40.f));
        break;
    case 17:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY * 1.5f, coordonate);
        break;
    case 18:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY * 1.5f, this, coordonate);
        break;
    case 19:
        Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
        break;
    case 20:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 40.f));
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y + 40.f));
        break;
    case 21:
        
        break;
    default:
        if (mDifficulty->GetValue() > 50)
        {
            mIsFinich = true;
        }
        else
        {
            mDifficulty->SetValue(0);
        }
    }
}

int Level2::GetTypeScene()
{
    return LEVEL2;
}