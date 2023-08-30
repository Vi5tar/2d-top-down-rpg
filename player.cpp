#include <iostream>
#include "player.h"

Player::Player()
{
    x = 44;
    y = 51;
    orientation = Direction::DOWN;
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
}

void Player::moveRight()
{
    x++;
}

void Player::moveUp()
{
    y--;
}

void Player::moveDown()
{
    y++;
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
    sprite.setScale(3, 3);
    sprite.setPosition(position);
}