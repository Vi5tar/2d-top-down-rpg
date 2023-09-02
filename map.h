#include <SFML/Graphics.hpp>
#include <vector>
#include "gameTile.h"
#include "location.h"

#ifndef MAP_H
#define MAP_H

class Map
{
    void buildMap(std::string, std::map<std::pair<int,int>, Location>);

public:
    std::vector<std::vector<GameTile *>> tiles;
    Map(std::string, std::map<std::pair<int,int>, Location>);
    //HACK: This gets rid of a "No default constructor exists for class Map" error but I'm not sure if there are unwanted side effects.
    Map() = default;
};

#endif