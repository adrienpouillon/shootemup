#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
class Twilight : public sf::Drawable, public sf::Transformable
{
protected:
	bool mIsHidden;
	bool* mLight;
	SpriteManager* mSpriteManager;

public:
	Twilight();

	virtual void Init(bool* light, std::string path);

	virtual void Init(bool* light, std::string path, int isEntity, sf::Vector2i size);

	virtual void Init(std::string path, int isEntity, sf::Vector2i size, int index);

	void CreatNewSprite(std::string path, int isEntity, sf::Vector2i size, int index);

	virtual void Texturing();

	virtual void Update(float timeFrame);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	SpriteManager* GetSpriteManager();

	bool GetIsHidden();
};

