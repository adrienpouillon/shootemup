#include "pch.h"
#include "Twilight.h"
#include "define.h"

Twilight::Twilight()
{
}

//initilisation rapide
void Twilight::Init(bool* light, std::string path)
{
	//considerer comme une entite
	CreatSpriteManager(light, path, ISENTITY, SPRITESIZEDEFAULT, SPRITESCALEDEFAULT);
}

void Twilight::Init(bool* light, std::string path, sf::Vector2i size, int isEntity, sf::Vector2i scale)
{
	CreatSpriteManager(light, path, isEntity, size, scale);
}

void Twilight::CreatSpriteManager(bool* light, std::string path, int isEntity, sf::Vector2i size, sf::Vector2i scale)
{
	mSpriteManager = new SpriteManager();
	mLight = light;

	//considerer comme le premier sprite creer
	int dumb = InitSpriteManager(path, isEntity, size, scale);
}

int Twilight::InitSpriteManager(std::string path, int isEntity, sf::Vector2i size, sf::Vector2i scale)
{
	return mSpriteManager->Init(path, isEntity, size, scale);
}

int Twilight::CreatNewSprite(std::string path, int isEntity, sf::Vector2i size, sf::Vector2i scale)
{
	return InitSpriteManager(path, isEntity, SPRITESIZEDEFAULT, scale);
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


