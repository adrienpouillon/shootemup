#pragma once
#include "Text.h"
#include "define.h"
class Score : public Text
{
protected:

public:
	Score(sf::Vector2f pos, int value);

	virtual void PrintText();

	virtual int GetTypeText();
};

