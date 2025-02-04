#include "pch.h"
#include "Light.h"
#include <iostream>


Light::Light() : Twilight()
{

}

void Light::Init(bool* light, std::string path)
{
	Twilight::Init(light, path);
}

void Light::Init(bool* light, std::string path, int isEntity, sf::Vector2i size, sf::Vector2i scale)
{
	Twilight::Init(light, path, size, isEntity, scale);
}

//invisible dans la lumiere
void Light::Texturing()
{
	if ((*mLight) == true)
	{
		//si lumiere
		//invisible
		mIsHidden = true;
	}
	else
	{
		//si ombre
		//visible
		mIsHidden = false;
	}
}

void Light::Update(float timeFrame)
{
	Twilight::Update(timeFrame);
}

void Light::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (mIsHidden == false)
	{
		states.transform.combine(this->getTransform());
		target.draw(mSpriteManager->GetCurrentSprite(), states);
	}
}