#include "pch.h"
#include "LevelText.h"

LevelText::LevelText() : Text()
{

}

void LevelText::Init(sf::Vector2f pos, int value)
{
	Text::Init(pos, value);
}

void LevelText::PrintText()
{
	mText.setString("Level : " + std::to_string(mValue));
}

int LevelText::GetTypeText()
{
	return DIFFICULTY;
}

