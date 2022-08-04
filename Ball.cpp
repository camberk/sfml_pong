#include "Ball.h"
#include <iostream>
#include <cmath>

void Ball::initVars() {
    this->ballShape.setFillColor(sf::Color::White);
    this->ballShape.setRadius(20.f);
    this->ballShape.setPosition(sf::Vector2f(960.f,540.f));
    this->maxXVel = 15;
    this->maxYVel = 15;
    this->xVel = this->maxXVel;
    this->yVel = 0;
}

Ball::Ball()
{
    this->initVars();
}

Ball::~Ball()
{

}

const sf::CircleShape Ball::getShape() const {
    return this->ballShape;
}

const sf::Vector2f& Ball::getPosition() const {
    return this->ballShape.getPosition();
}

void Ball::updateBallPosition() {
    this->ballShape.move(sf::Vector2f(-this->xVel, this->yVel));
}

void Ball::updateVelocity(float y) {
    this->xVel = -xVel;
    if(std::abs(this->yVel) < this->maxYVel) {
        this->yVel = y;
    }
    else {
        this->yVel = this->maxYVel;
    }
}

void Ball::updateWindowBoundsCollision(const sf::RenderTarget* target) {
    if(this->ballShape.getGlobalBounds().left <= 0.f) { // left
        this->xVel *= -1;
    }
    if(this->ballShape.getGlobalBounds().left + this->ballShape.getGlobalBounds().width >= target->getSize().x) { //right
        this->xVel *= -1;
    }

    if(this->ballShape.getGlobalBounds().top <= 0.f) { // top
        this->yVel *= -1;
    }
    if(this->ballShape.getGlobalBounds().top + this->ballShape.getGlobalBounds().height >= target->getSize().y) { //bottom
        this->yVel *= -1;
    }
}

void Ball::update(const sf::RenderTarget* target) {
    this->updateWindowBoundsCollision(target);
    this->updateBallPosition();
    std::cout << this->yVel << std::endl;
}

void Ball::render(sf::RenderTarget* target) {
    target->draw(this->ballShape);
}