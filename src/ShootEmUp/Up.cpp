#include "pch.h"
#include "Up.h"

Up::Up(sf::Vector2f pos, int value) : Text(pos, value)
{

}

void Up::PrintText()
{
	mText.setString("Up : " + std::to_string(mValue));
}

int Up::GetTypeText()
{
	return LIFE;
}