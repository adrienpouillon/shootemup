#include "pch.h"
#include "Map.h"
#include "define.h"


Map::Map() : Entity(), Twilight()
{
}

void Map::Init(sf::Vector2f pos, bool* light, std::string path)
{
	Twilight::Init(light, path, ISNOTENTITY, sf::Vector2i(1920, 1080));
	Entity::Init(sf::Vector2f(50.f, 0.f), pos);
}

void Map::Move(float timeFrame)
{
	if (GetPosition().x <= -1920)
	{
		SetPosition(sf::Vector2f(1920, 0));
	}
	Entity::Move(timeFrame);
}

//Mise a jour
void Map::Update(float timeFrame)
{
	Move(timeFrame);
	Twilight::Update(timeFrame);
}

int Map::GetType()
{
	return COLLIDEMAP;
}

SpriteManager* Map::GetSpriteManager()
{
	return mSpriteManager;
}

sf::Vector2f Map::GetPosition()
{
	return getPosition();
}

void Map::SetPosition(sf::Vector2f pos)
{
	return setPosition(pos);
}
