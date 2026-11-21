#pragma once
#include "Text.h"
#include "define.h"
class UpText : public Text
{
protected:

public:
	UpText();

	void Init(sf::Vector2f pos, int value);

	virtual void PrintText();

	virtual int GetTypeText();
};

