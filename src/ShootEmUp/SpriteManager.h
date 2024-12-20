#pragma once
#include <SFML/Graphics.hpp>

class SpriteManager
{
protected:
	sf::Sprite mCurrentSprite;
	int mFrame;
	sf::Texture mTileMap;
	sf::Texture mCurrentAnimation;
	bool mIsEntity;
	sf::Vector2f mSize;
	float mElapsedTime;

public:
	SpriteManager(std::string path, bool isEntity);

	void LoadCurrentAnimation(sf::Vector2i position, sf::Vector2f size);

	void LoadCurrentSprite(sf::Vector2f size, float timeFrame);

	sf::Sprite GetCurrentSprite();

	sf::Vector2f GetSize();

	sf::Vector2f GetPosition();

	void Update(float timeFrame);
};
