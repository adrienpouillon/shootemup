#pragma once
#include "Twilight.h"
#include "Enemy.h"

class Light : public Twilight
{
protected:

public:
	Light();

	virtual void Init(bool* light, std::string path);

	void Init(bool* light, std::string path, int isEntity, sf::Vector2i size, sf::Vector2i scale);

	virtual void Texturing();

	virtual void Update(float timeFrame) override;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};