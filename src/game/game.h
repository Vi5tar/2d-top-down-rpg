#include "maps/map.h"
#include "player/player.h"
#include "maps/mapName.h"
#include "maps/location.h"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    sf::IntRect getLoadArea(int, int);
    void loadUpcomingTiles();
    bool canMove(Player *, Direction);
    void setCurrentMap(MapName);

public:
    Map currentMap;
    Player *player;
    Game(Location);
    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerUp();
    void movePlayerDown();
    void setPlayerLocation(Location);
    void saveState();
    void loadState();
};

#endif