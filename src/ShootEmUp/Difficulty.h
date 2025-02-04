#pragma once
#include "Text.h"
#include "define.h"
class Difficulty : public Text
{
protected:

public:
	Difficulty();

	void Init(sf::Vector2f pos, int value);

	virtual void PrintText();

	virtual int GetTypeText();
};

