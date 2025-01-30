#pragma once
#include "Shadow.h"
class Ghost : public Enemy, public Shadow
{
protected:
	float mTimeVisible;
	float mTimeVisibleStay;
	bool IsShadow;
	sf::Vector2f velocityVisible;
	sf::Vector2f velocityInvisible;
public:
	Ghost();

	virtual void Init(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position, float timeVisible);

	void TimeVisibleLess(float n);

	void Update(float timeFrame);

	void UpdateVelocity();

	int GetType();

	bool GetIsHidden();

	int GetScore();

	SpriteManager* GetSpriteManager();

	sf::Vector2f GetPosition();

	void SetPosition(sf::Vector2f pos);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

