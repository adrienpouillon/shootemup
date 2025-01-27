#pragma once
#include "Text.h"
#include "define.h"
class Up : public Text
{
protected:

public:
	Up(sf::Vector2f pos, int value);

	virtual void PrintText();

	virtual int GetTypeText();
};

