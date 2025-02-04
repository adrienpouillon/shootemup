#include "pch.h"
#include "Shadow.h"
#include <iostream>


Shadow::Shadow() : Twilight()
{
	
}

void Shadow::Init(bool* light, std::string path)
{
	Twilight::Init(light, path);
}

void Shadow::Init(bool* light, std::string path, int isEntity, sf::Vector2i size, sf::Vector2i scale)
{
	Twilight::Init(light, path, size, isEntity, scale);
}

//invisible dans l'ombre
void Shadow::Texturing()
{
	if ((*mLight) == true)
	{
		//si lumiere
		//visible
		mIsHidden = false;
	}
	else
	{
		//si ombre
		//invisible
		mIsHidden = true;
	}
}

void Shadow::Update(float timeFrame)
{
	Twilight::Update(timeFrame);
}

void Shadow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (mIsHidden == false)
	{
		states.transform.combine(this->getTransform());
		target.draw(mSpriteManager->GetCurrentSprite(), states);
	}
}