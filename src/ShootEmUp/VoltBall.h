#pragma once
#include "Shot.h"
#include "Twilight.h"
class VoltBall :public Shot, public Twilight
{
protected:

public:
    VoltBall();

    void Init(int type, std::string path, bool* light, sf::Vector2f velocity, sf::Vector2f position);

    void Update(float timeFrame) override;

    virtual bool CanCollideWithEntity(Twilight* entity);

    virtual int GetType();

    SpriteManager* GetSpriteManager();

    sf::Vector2f GetPosition();

    void SetPosition(sf::Vector2f pos);

};