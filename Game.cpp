#include "Game.h"

void Game::initVars() {
    // init window dynamically
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "PONG", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60); // limit the framereate
}

Game::Game()
{
    this->initVars();
}

Game::~Game()
{
    delete this->window;
}

void Game::run() {
    while(this->window->isOpen()) {
        this->update();
        this->render();
    }
}

void Game::pollEvents() {
    while(this->window->pollEvent(this->event)) {
        if(this->event.type == sf::Event::Closed) {
            this->window->close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->window->close();
        }
    }
}

void Game::updateCollision() {
    
}

void Game::update() {
    this->pollEvents();
    this->p1.update(this->window); // call player update function
    this->ball.update(this->window);
}

void Game::render() {
    this->window->clear(); // clear old window

    // TODO: draw stuff here
    this->p1.render(this->window); // call player render function
    this->ball.render(this->window);

    this->window->display(); // display new drawing
}