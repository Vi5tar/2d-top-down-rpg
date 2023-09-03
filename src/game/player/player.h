#include <SFML/Graphics.hpp>
#include "direction.h"
#include "../maps/location.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    int x;
    int y;
    Direction orientation;

public:
    sf::Texture texture;
    sf::Sprite sprite;
    bool hasMoved;
    Player();
    int getX();
    int getY();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void setOrientation(Direction);
    void setSprite(sf::Vector2f, int);
    void setLocation(Location);
};

#endif