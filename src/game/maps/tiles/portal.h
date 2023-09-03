#include "gameTile.h"
#include "../location.h"

#ifndef PORTAL_H
#define PORTAL_H

class Portal : public GameTile
{
public:
    Location destination;
    Portal(std::string, bool, Location);
    bool isPortal();
};

#endif