#include "pch.h"
#include "Up.h"

Up::Up() : Text()
{

}

void Up::Init(sf::Vector2f pos, int value)
{
	Text::Init(pos, value);
}

void Up::PrintText()
{
	mText.setString("Up : " + std::to_string(mValue));
}

int Up::GetTypeText()
{
	return LIFE;
}