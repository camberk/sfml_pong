#pragma once

#include "Ball.h"

class Player
{
private:
    sf::RectangleShape paddleShape;

    int moveSpeed;
    int direction;

    void initVars();

public:
    Player();
    ~Player();

    const sf::RectangleShape getShape() const;
    const int getDirection() const;

    void updateMovement();
    void checkBounds(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);

};