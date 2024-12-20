#pragma once

#include <SFML/Graphics.hpp>

#define FONTPATH "../../../res/Pixel Times.ttf"

class Text : public sf::Drawable, sf::Transformable
{
protected:
	int mValue;
	int mPrintText;
	sf::Text mText;
	sf::Font mFont;
public:
	Text(int printText, sf::Vector2f pos, int value);

	void Increase(int amount);

	void Lower(int amount);

	void SetValue(int amount);

	void PrintText();

	int GetValue();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

