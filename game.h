#include "map.h"
#include "player.h"
#include "mapName.h"
#include "location.h"

#ifndef GAME_H
#define GAME_H

class Game
{

public:
    Map currentMap;
    Player* player;
    Game(MapName, Location);
    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerUp();
    void movePlayerDown();
    bool canMove(Player*, Direction);
    void setCurrentMap(MapName);
    void setPlayerLocation(Location);
};

#endif