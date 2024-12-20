#include "pch.h"
#include "Shadow.h"
#include <iostream>


Shadow::Shadow(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position) : Enemy(up, path, velocity, position)
{
	mLight = light;
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