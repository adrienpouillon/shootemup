#include "pch.h"
#include "DifficultyText.h"

DifficultyText::DifficultyText() : Text()
{

}

void DifficultyText::Init(sf::Vector2f pos, int value)
{
	Text::Init(pos, value);
}

void DifficultyText::PrintText()
{
	mText.setString("Difficulte : " + std::to_string(mValue));
}

int DifficultyText::GetTypeText()
{
	return DIFFICULTY;
}