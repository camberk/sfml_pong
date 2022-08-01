#pragma once

#include "Player.h"
#include <iostream>



class Game
{
private:
    sf::RenderWindow* window;
    sf::Event event; // used for event polling

    Player p1;
    Ball ball;

    // init functions
    void initVars();
public:
    Game();
    ~Game();

    // functions
    void run();
    void pollEvents();
    void updateCollision();

    void update();
    void render();

};