#pragma once

#include "Ball.h"

class comp
{
private:
    sf::RectangleShape paddleShape;

    int moveSpeed;
    int direction;

    void initVars(sf::Vector2f startPos);

public:
    comp(sf::Vector2f startPos);
    ~comp();

    const sf::RectangleShape getShape() const;
    const int getDirection() const;

    void updateMovement(sf::Vector2f pos);
    void checkBounds(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);

};