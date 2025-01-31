#include "pch.h"
#include "Twilight.h"
#include "define.h"

Twilight::Twilight()
{
}

void Twilight::Init(bool* light, std::string path)
{
	//considerer comme une entite
	Init(light, path, ISENTITY, SPRITESIZEDEFAULT);
}

void Twilight::Init(bool* light, std::string path, int isEntity, sf::Vector2i size)
{
	mSpriteManager = new SpriteManager();
	mLight = light;

	//considerer comme le premier sprite creer
	Init(path, isEntity, size, FIRSTINDEX);
}

void Twilight::Init(std::string path, int isEntity, sf::Vector2i size, int index)
{
	if (isEntity == ISENTITY)
	{
		mSpriteManager->Init(path, size, index);
	}
	else
	{
		mSpriteManager->Init(path, isEntity, size, index);
	}
}

void Twilight::CreatNewSprite(std::string path, int isEntity, sf::Vector2i size, int index)
{
	Twilight::Init(path, ISENTITY, SPRITESIZEDEFAULT, index);
}

void Twilight::Texturing()
{
	mIsHidden = false;
}

void Twilight::Update(float timeFrame)
{
	Texturing();
	mSpriteManager->Update(timeFrame);
}

void Twilight::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());
    target.draw(mSpriteManager->GetCurrentSprite(), states);
}

SpriteManager* Twilight::GetSpriteManager()
{
	return mSpriteManager;
}

bool Twilight::GetIsHidden()
{
	return mIsHidden;
}


