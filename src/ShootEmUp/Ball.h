#pragma once
#include "Twilight.h"
#include "Shot.h"

class Ball :public Shot, public Twilight
{
protected:

public:
    Ball();

    void Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position);

    //mise a jour
    void Update(float timeFrame);

    virtual bool CanCollideWithEntity(Twilight* entity);

    SpriteManager* GetSpriteManager();

    sf::Vector2f GetPosition();

    void SetPosition(sf::Vector2f pos);
};


