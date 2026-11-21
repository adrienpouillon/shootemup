#pragma once
#include "Text.h"
#include "define.h"
class DifficultyText : public Text
{
protected:

public:
	DifficultyText();

	void Init(sf::Vector2f pos, int value);

	virtual void PrintText();

	virtual int GetTypeText();
};

