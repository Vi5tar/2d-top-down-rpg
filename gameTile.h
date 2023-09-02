#include <SFML/Graphics.hpp>
#include "location.h"

#ifndef GAMETILE_H
#define GAMETILE_H

class GameTile
{
public:
    bool walkable;
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;
    GameTile(std::string, bool);
    bool setUpSprite(std::string);
    bool isWalkable();
    static GameTile *getTile(int, bool, Location);
    virtual bool isPortal();
};

#endif