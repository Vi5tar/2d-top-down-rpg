#include "maps/map.h"
#include "player/player.h"
#include "maps/mapName.h"
#include "maps/location.h"

#ifndef GAME_H
#define GAME_H

class Game
{

public:
    Map currentMap;
    Player* player;
    Game(Location);
    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerUp();
    void movePlayerDown();
    bool canMove(Player*, Direction);
    void setCurrentMap(MapName);
    void setPlayerLocation(Location);
};

#endif