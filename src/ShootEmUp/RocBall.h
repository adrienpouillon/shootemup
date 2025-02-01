#pragma once
#include "Shot.h"
#include "Twilight.h"
#include "Ball.h"
class RocBall :public Shot, public Twilight
{
protected:

public:
    RocBall();

    void Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position);

    void Update(float timeFrame);

    virtual void TouchEntity();

    virtual bool CanCollideWithEntity(Twilight* entity);

    virtual int GetType();

    SpriteManager* GetSpriteManager();

    sf::Vector2f GetPosition();

    void SetPosition(sf::Vector2f pos);

};