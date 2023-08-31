#include <vector>
#include "gameTile.h"

#ifndef MAP_H
#define MAP_H

class Map
{
    void buildMap(std::string);

public:
    std::vector<std::vector<GameTile *>> tiles;
    Map(std::string);
    //HACK: This gets rid of a "No default constructor exists for class Map" error but I'm not sure if there are unwanted side effects.
    Map() = default;
};

#endif