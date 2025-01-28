#pragma once
#include "Shadow.h"
#include "Define.h"
class Scarabe :public Shadow
{
protected:
	
public:
	Scarabe();

	virtual void Init(int up, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position);

	void Update(float timeFrame);

	int GetType();

	int GetScore();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

