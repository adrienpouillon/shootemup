#pragma once
#include <SFML/Graphics.hpp>

class SpriteManager
{
protected:
	sf::Sprite mCurrentSprite;
	int mFrame;
	std::vector <sf::Texture> mTileMap;
	std::vector <sf::Vector2i> mSize;
	sf::Texture mCurrentAnimation;
	int mIsEntity;
	int mIndex;
	float mElapsedTime;

public:
	SpriteManager();

	void Init(std::string path, sf::Vector2i size, int index);

	void Init(std::string path, int isEntity, sf::Vector2i size, int index);

	void Init(std::string path, int isEntity, sf::Vector2i size, sf::Vector2i scale, int index);

	void LoadCurrentAnimation(sf::Vector2i position, sf::Vector2i size);

	void LoadCurrentSprite(sf::Vector2i size, float timeFrame);

	void Update(float timeFrame);

	sf::Sprite GetCurrentSprite();

	sf::Vector2f GetSize();

	sf::FloatRect GetCollision();

	sf::Vector2f GetPosition();

	void SetIndex(int index);

	int GetIndex();

};
