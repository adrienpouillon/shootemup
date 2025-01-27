#pragma once
#include "Text.h"
#include "define.h"
class Difficulty : public Text
{
protected:

public:
	Difficulty(sf::Vector2f pos, int value);

	virtual void PrintText();

	virtual int GetTypeText();
};

