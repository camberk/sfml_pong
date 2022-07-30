#include "Ball.h"

void Ball::initVars() {
    this->ballShape.setFillColor(sf::Color::White);
    this->ballShape.setRadius(20.f);
    this->ballShape.setPosition(sf::Vector2f(960.f,540.f));
    this->maxVel = 20;
    this->xVel = 10;
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

void Ball::updateBallPosition() {
    this->ballShape.move(sf::Vector2f(-this->xVel, this->yVel));
}

void Ball::update(const sf::RenderTarget* target) {
    this->updateBallPosition();
}

void Ball::render(sf::RenderTarget* target) {
    target->draw(this->ballShape);
}