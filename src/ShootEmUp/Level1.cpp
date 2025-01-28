#include "pch.h"
#include "Level1.h"
//Shot(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, coordonate)
//Aureon(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate)
//Rat(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate)
//Skarnaugh(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate)
//Ghost(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, coordonate, TIMEGHOSTHIDDEN)
//Scarabe(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate)




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


Level1::Level1() : Scene()
{
    
}

void Level1::Init(Text* score, float timeGenerate)
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
    Add<Player>()->Init(PLAYERUP, PLAYERPATH, &mLight, PLAYERVELOCITY, SCENEID, sf::Vector2f(200, 540), mLife);
    mGenerateEnemy = 100;
}

void Level1::ChooseEnnemy(sf::Vector2f coordonate, int randomEnemy)
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
        Add<Ghost>()->Init(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, coordonate, TIMEGHOSTHIDDEN);
        break;
    case 2:
        Add<Shot>()->Init(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, coordonate);
        break;
    case 3:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 4:

        break;
    case 5:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 6:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 7:

        break;
    case 8:
        Add<Shot>()->Init(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, coordonate);
        break;
    case 9:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 10:
        Add<Scarabe>()->Init(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate);
        break;
    case 11:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 12:
        Add<Shot>()->Init(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, coordonate);
        break;
    case 13:
        
        break;
    case 14:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY * 1.5f, coordonate);
        break;
    case 15:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate);
        break;
    case 16:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate);
        break;
    case 17:
        Add<Skarnaugh>()->Init(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate);
        break;
    case 18:
        Add<Aureon>()->Init(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY * 1.5f, this, coordonate);
        break;
    case 19:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY * 1.5f, coordonate);
        break;
    case 20:
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 40.f));
        Add<Rat>()->Init(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y + 40.f));
        break;
    case 21:
        
        break;
    case 22:

        break;
    case 23:

        break;
    case 24:

        break;
    case 25:

        break;
    case 26:

        break;
    case 27:

        break;
    case 28:

        break;
    case 29:

        break;
    case 30:

        break;
    default:
        if (mDifficulty->GetValue() > 22)
        {
            mIsFinich = true;
        }
        else
        {
            mDifficulty->SetValue(0);
        }
        break;
    }
}

int Level1::GetTypeScene()
{
    return LEVEL1;
}