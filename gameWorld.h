#include "map.h"
#include "player.h"
#include "mapName.h"
#include "location.h"

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld
{

public:
    Map currentMap;
    Player* player;
    GameWorld(MapName, Location);
    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerUp();
    void movePlayerDown();
    bool canMove(Player*, Direction);
    void setCurrentMap(MapName);
    void setPlayerLocation(Location);
};

#endif