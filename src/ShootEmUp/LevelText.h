#pragma once
#include "Text.h"
#include "define.h"
class LevelText : public Text
{
protected:

public:
	LevelText();

	void Init(sf::Vector2f pos, int value);

	virtual void PrintText();

	virtual int GetTypeText();
};
