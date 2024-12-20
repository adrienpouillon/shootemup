#include "pch.h"
#include "Light.h"
#include <iostream>


Light::Light(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position) : Enemy(up, path, velocity, position)
{
	mLight = light;
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