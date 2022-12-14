#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Ball
{
private:
    sf::CircleShape ballShape;

    int maxXVel;
    int maxYVel;
    int xVel;
    int yVel;

    void initVars();

public:
    Ball();
    ~Ball();

    const sf::CircleShape getShape() const;
    const sf::Vector2f& getPosition() const;

    void updateBallPosition();
    void updateVelocity(float y);
    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);

};