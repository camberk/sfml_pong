#pragma once

#include "Ball.h"

class Player
{
private:
    sf::RectangleShape paddleShape;

    int moveSpeed;

    void initVars();

public:
    Player();
    ~Player();

    void updateMovement();
    void checkBounds(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);

};