#include <SFML/Graphics.hpp>

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
    virtual bool isPortal();
};

#endif