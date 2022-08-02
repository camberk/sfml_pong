#pragma once

#include "Ball.h"

class Player
{
private:
    sf::RectangleShape paddleShape;

    int moveSpeed;
    int direction;

    void initVars(sf::Vector2f startPos);

public:
    Player(sf::Vector2f startPos);
    ~Player();

    const sf::RectangleShape getShape() const;
    const int getDirection() const;

    void updateMovement();
    void checkBounds(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);

};