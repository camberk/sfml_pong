#include "Player.h"

void Player::initVars() {
    this->moveSpeed = 15;
    this->paddleShape.setSize(sf::Vector2f(30.f,150.f));
    this->paddleShape.setFillColor(sf::Color::White);
    this->paddleShape.setPosition(sf::Vector2f(20.f, 0.f));
}

Player::Player()
{
    this->initVars();
}

Player::~Player()
{

}

const sf::RectangleShape Player::getShape() const {
    return this->paddleShape;
}

const int Player::getDirection() const {
    return this->direction;
}

void Player::updateMovement() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->paddleShape.move(0.f, -moveSpeed);
        this->direction = -1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->paddleShape.move(0.f, moveSpeed);
        this->direction = 1;
    }
}

void Player::checkBounds(const sf::RenderTarget* target) {
    if(this->paddleShape.getGlobalBounds().top <= 0) {
        this->paddleShape.setPosition(paddleShape.getGlobalBounds().width, 0.f);
    }
    if(this->paddleShape.getGlobalBounds().top + this->paddleShape.getGlobalBounds().height >= target->getSize().y) {
        this->paddleShape.setPosition(paddleShape.getGlobalBounds().left, target->getSize().y - this->paddleShape.getGlobalBounds().height);
    }
}

void Player::update(const sf::RenderTarget* target) {
    this->updateMovement();
    this->checkBounds(target);
}

void Player::render(sf::RenderTarget* target) {
    target->draw(this->paddleShape);
}