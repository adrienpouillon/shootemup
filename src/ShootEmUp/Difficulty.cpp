#include "pch.h"
#include "Difficulty.h"

Difficulty::Difficulty() : Text()
{

}

void Difficulty::Init(sf::Vector2f pos, int value)
{
	Text::Init(pos, value);
}

void Difficulty::PrintText()
{
	mText.setString("Difficulte : " + std::to_string(mValue));
}

int Difficulty::GetTypeText()
{
	return DIFFICULTY;
}