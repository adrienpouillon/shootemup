#include "pch.h"
#include "Difficulty.h"

Difficulty::Difficulty(sf::Vector2f pos, int value) : Text(pos, value)
{

}

void Difficulty::PrintText()
{
	mText.setString("Difficulte : " + std::to_string(mValue));
}

int Difficulty::GetTypeText()
{
	return DIFFICULTY;
}