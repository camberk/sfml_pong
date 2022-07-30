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

    int maxVel;
    int xVel;
    int yVel;

    void initVars();

public:
    Ball();
    ~Ball();

    const sf::CircleShape getShape() const;

    void updateBallPosition();

    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);

};