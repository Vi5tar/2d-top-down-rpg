#include "../map.h"
#include "../mapName.h"

#ifndef MAPFACTORY_H
#define MAPFACTORY_H

class MapFactory
{
    public:
        static Map getMap(MapName);
};

#endif