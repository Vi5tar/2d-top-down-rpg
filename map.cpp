#include <fstream>
#include <sstream>
#include "map.h"

Map::Map(std::string mapDefinition)
{
    buildMap(mapDefinition);
}

void Map::buildMap(std::string mapDefinition)
{
    std::ifstream world(mapDefinition);
    for(std::string line; getline(world, line);)
    {
        std::stringstream ss(line);
        std::vector<GameTile *> row;
        for (int i; ss >> i;) {
            GameTile *tile = GameTile::getTile(i);
            row.push_back(tile);
            if (ss.peek() == ' ')
                ss.ignore();
        }
        tiles.push_back(row);
    }
}