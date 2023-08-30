#include <SFML/Graphics.hpp>
#include <vector>
#include "gameTile.h"
#include "player.h"

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld
{
    void buildWorldMap();

public:
    std::vector<std::vector<GameTile *>> worldMap;
    Player* player;
    GameWorld();
    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerUp();
    void movePlayerDown();
    bool canMove(Player*, Direction);
};

#endif