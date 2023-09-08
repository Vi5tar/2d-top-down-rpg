#include <SFML/Graphics.hpp>
#include <vector>
#include "tiles/gameTile.h"
#include "../player/direction.h"
#include "mapName.h"
#include "location.h"

#ifndef MAP_H
#define MAP_H

class Map
{
public:
    MapName name;
    std::vector<std::vector<int>> layout;
    std::map<std::pair<int, int>, Location> portals;
    std::map<std::pair<int, int>, GameTile *> tiles;
    Map(MapName, std::vector<std::vector<int>>, std::map<std::pair<int, int>, Location>);
    // HACK: This gets rid of a "No default constructor exists for class Map" error but I'm not sure if there are unwanted side effects.
    Map() = default;
    void loadTiles(sf::IntRect);
};

#endif