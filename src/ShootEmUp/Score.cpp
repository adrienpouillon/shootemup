#include "pch.h"
#include "Score.h"

Score::Score(sf::Vector2f pos, int value) : Text(pos, value)
{

}

void Score::PrintText()
{
	mText.setString("Score : " + std::to_string(mValue));
}

int Score::GetTypeText()
{
	return SCORE;
}