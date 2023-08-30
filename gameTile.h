#include <SFML/Graphics.hpp>

#ifndef GAMETILE_H
#define GAMETILE_H

class GameTile
{
public:
    bool walkable;
    bool isExit;
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;
    GameTile(std::string, bool, bool);
    bool setUpSprite(std::string);
    bool isWalkable();
    static GameTile *getTile(int);
};

#endif