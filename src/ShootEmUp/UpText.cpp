#include "pch.h"
#include "UpText.h"

UpText::UpText() : Text()
{

}

void UpText::Init(sf::Vector2f pos, int value)
{
	Text::Init(pos, value);
}

void UpText::PrintText()
{
	mText.setString("Up : " + std::to_string(mValue));
}

int UpText::GetTypeText()
{
	return LIFE;
}