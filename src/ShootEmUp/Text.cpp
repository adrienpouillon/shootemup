#include "pch.h"
#include "Text.h"
#include "define.h"

Text::Text()
{

}

Text::Text(sf::Vector2f pos, int value)
{
	mValue = value;
	setPosition(pos);

	if (!mFont.loadFromFile(FONTPATH))
	{
		exit(404);
	}

	// select the font
	mText.setFont(mFont); // font is a sf::Font

	// set the string to display
	//PrintText();

	// set the character size
	mText.setCharacterSize(48); // in pixels, not points!

	// set the color
	mText.setFillColor(sf::Color::Yellow);

	// set the text style
	mText.setStyle(sf::Text::Bold);
}

void Text::Init(sf::Vector2f pos, int value)
{
	mValue = value;
	setPosition(pos);

	if (!mFont.loadFromFile(FONTPATH))
	{
		exit(404);
	}

	// select the font
	mText.setFont(mFont); // font is a sf::Font

	// set the string to display
	//PrintText();

	// set the character size
	mText.setCharacterSize(48); // in pixels, not points!

	// set the color
	mText.setFillColor(sf::Color::Yellow);

	// set the text style
	mText.setStyle(sf::Text::Bold);
}


void Text::Increase(int amount)
{
	mValue += amount;
}

void Text::Lower(int amount)
{
	mValue -= amount;
}

void Text::SetValue(int amount)
{
	mValue = amount;
}

void Text::Update()
{
	PrintText();
}

int Text::GetValue()
{
	return mValue;
}

void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());
	target.draw(mText, states);
}