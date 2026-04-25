#include "gameTile.h"

#ifndef DOOR_H
#define DOOR_H

class Door : public GameTile
{
    bool open;
public:
    Door(std::string, bool);
    bool isWalkable();
    void toggleOpen();
};

#endif
