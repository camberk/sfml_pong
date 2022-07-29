#pragma once

#include "Player.h"



class Game
{
private:
    sf::RenderWindow* window;
    sf::Event event; // used for event polling

    Player p1;

    // init functions
    void initVars();
public:
    Game();
    ~Game();

    // functions
    void run();
    void pollEvents();
    void update();
    void render();

};