#include "../tiles/gameTile.h"
#include "../location.h"

#ifndef GAMETILEFACTORY_H
#define GAMETILEFACTORY_H

class GameTileFactory
{
    public:
        static GameTile *getTile(int, bool, Location);
};

#endif