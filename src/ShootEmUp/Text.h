#pragma once

#include <SFML/Graphics.hpp>

#define FONTPATH "../../../res/Pixel Times.ttf"

class Text : public sf::Drawable, sf::Transformable
{
protected:
	int mValue;
	sf::Text mText;
	sf::Font mFont;
public:

	Text();

	Text(sf::Vector2f pos, int value);

	void Init(sf::Vector2f pos, int value);

	void Increase(int amount);

	void Lower(int amount);

	void SetValue(int amount);

	virtual void Update();

	virtual void PrintText() = 0;

	virtual int GetTypeText() = 0;

	int GetValue();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

