#include "pch.h"
#include "Map.h"
#include "define.h"


Map::Map(std::string path) : Entity(path, sf::Vector2f(50.f, 0.f), sf::Vector2f(0.f, 0.f), 0)
{//vide
}

void Map::Move(float timeFrame)
{
	if (getPosition().x <= -1920)
	{
		setPosition(sf::Vector2f(1920, 0));
	}
	Entity::Move(timeFrame);
}

//Mise a jour
void Map::Update(float timeFrame)
{
	Move(timeFrame);
	mSpriteManager->Update(timeFrame);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());
	target.draw(mSpriteManager->GetCurrentSprite(), states);
}

int Map::GetType()
{
	return COLLIDEMAP;
}
