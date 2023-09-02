#include <iostream>
#include "player.h"
#include "windowConfig.h"

Player::Player()
{
    x = 10;
    y = 10;
    orientation = Direction::DOWN;
    hasMoved = false;
}

int Player::getX()
{
    return x;
}

int Player::getY()
{
    return y;
}

void Player::moveLeft()
{
    x--;
    hasMoved = true;
}

void Player::moveRight()
{
    x++;
    hasMoved = true;
}

void Player::moveUp()
{
    y--;
    hasMoved = true;
}

void Player::moveDown()
{
    y++;
    hasMoved = true;
}

void Player::setOrientation(Direction direction)
{
    orientation = direction;
}

void Player::setSprite(sf::Vector2f position, int step)
{
    std::string texturePath = "assets/16x16Tiles/dw-hero-" + std::to_string((int)orientation) + "-" + std::to_string(step) + ".png";
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
    sprite.setScale(SCALE_X, SCALE_Y);
    sprite.setPosition(position);
}

void Player::setLocation(Location location)
{
    x = location.position.x;
    y = location.position.y;
    setOrientation(location.orientation);
    hasMoved = false;
}