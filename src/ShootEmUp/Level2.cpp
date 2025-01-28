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
//Shot(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, coordonate)
//Aureon(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate)
//Rat(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate)
//Skarnaugh(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate)
//Ghost(GHOSTUP, GHOSTPATH, &mLight, GHOSTVELOCITY, coordonate, TIMEGHOSTHIDDEN)
//Scarabe(SCARABEUP, SCARABEPATH, &mLight, SCARABEVELOCITY, coordonate)


Level2::Level2(Text* score, float timeGenerate) : Scene(timeGenerate)
{
    //texte
    mScore = score;
    Add(score);
    mDifficulty = new Difficulty(sf::Vector2f(430.f, 30.f), 0);
    Add(mDifficulty);
    mLife = new Up(sf::Vector2f(830.f, 30.f), PLAYERUP);
    Add(mLife);

    //premiere entity (joueur ou menu)
    Add(new Map(MAPPATH));
    Add(new Map(MAPPATH));
    mEntities[1]->setPosition(sf::Vector2f(1920, 0));
    Add(new Player(PLAYERUP*3, PLAYERPATH, &mLight, PLAYERVELOCITY, SCENEID, sf::Vector2f(200, 540), mLife));
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
        Add(new Rat(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate));
        break;
    case 1:
        Add(new Rat(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate));
        break;
    case 2:
        Add(new Shot(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, coordonate));
        break;
    case 3:
        Add(new Rat(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate));
        break;
    case 4:
        Add(new Aureon(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate));
        break;
    case 5:
        Add(new Aureon(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate));
        break;
    case 6:
        Add(new Rat(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate));
        break;
    case 7:
        Add(new Rat(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate));
        break;
    case 8:
        Add(new Shot(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, coordonate));
        break;
    case 9:
        Add(new Rat(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate));
        break;
    case 10:
        Add(new Skarnaugh(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate));
        break;
    case 11:
        Add(new Aureon(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate));
        break;
    case 12:
        Add(new Shot(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 80.f)));
        Add(new Shot(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y)));
        Add(new Shot(SHOTTYPEENEMY, SHOTPATH, SHOTVELOCITY, sf::Vector2f(coordonate.x, coordonate.y + 80.f)));
        break;
    case 13:
        Add(new Aureon(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, coordonate));
        break;
    case 14:
        Add(new Rat(RATUP, RATPATH, &mLight, RATVELOCITY * 1.5f, coordonate));
        break;
    case 15:
        Add(new Rat(RATUP, RATPATH, &mLight, RATVELOCITY, coordonate));
        break;
    case 16:
        Add(new Aureon(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, sf::Vector2f(coordonate.x, coordonate.y - 40.f)));
        Add(new Aureon(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY, this, sf::Vector2f(coordonate.x, coordonate.y + 40.f)));
        break;
    case 17:
        Add(new Rat(RATUP, RATPATH, &mLight, RATVELOCITY * 1.5f, coordonate));
        break;
    case 18:
        Add(new Aureon(AUREONUP, AUREONPATH, &mLight, AUREONVELOCITY * 1.5f, this, coordonate));
        break;
    case 19:
        Add(new Skarnaugh(SKARNAUGHUP, SKARNAUGHPATH, &mLight, SKARNAUGHVELOCITY, this, coordonate));
        break;
    case 20:
        Add(new Rat(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y - 40.f)));
        Add(new Rat(RATUP, RATPATH, &mLight, RATVELOCITY, sf::Vector2f(coordonate.x, coordonate.y + 40.f)));
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