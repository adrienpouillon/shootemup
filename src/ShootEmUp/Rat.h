#pragma once

#include "Shadow.h"

class Rat : public Shadow
{
protected:

public:
	Rat(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position);

	void Update(float timeFrame) override;

	int GetType() override;

	int GetScore() override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};