#include "comp.h"

void comp::initVars(sf::Vector2f startPos) {
    this->moveSpeed = 15;
    this->paddleShape.setSize(sf::Vector2f(30.f,150.f));
    this->paddleShape.setFillColor(sf::Color::White);
    this->paddleShape.setPosition(startPos);
}

comp::comp(sf::Vector2f startPos)
{
    this->initVars(startPos);
}

comp::~comp()
{

}

const sf::RectangleShape comp::getShape() const {
    return this->paddleShape;
}

const int comp::getDirection() const {
    return this->direction;
}

void comp::updateMovement(sf::Vector2f pos) {
    this->paddleShape.setPosition(sf::Vector2f(this->paddleShape.getPosition().x, pos.y));
}

void comp::checkBounds(const sf::RenderTarget* target) {
    if(this->paddleShape.getGlobalBounds().top <= 0) {
        this->paddleShape.setPosition(paddleShape.getGlobalBounds().width, 0.f);
    }
    if(this->paddleShape.getGlobalBounds().top + this->paddleShape.getGlobalBounds().height >= target->getSize().y) {
        this->paddleShape.setPosition(paddleShape.getGlobalBounds().left, target->getSize().y - this->paddleShape.getGlobalBounds().height);
    }
}

void comp::update(const sf::RenderTarget* target) {
    this->checkBounds(target);
}

void comp::render(sf::RenderTarget* target) {
    target->draw(this->paddleShape);
}