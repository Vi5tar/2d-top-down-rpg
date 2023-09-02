#include <fstream>
#include <sstream>
#include "map.h"
#include "gameTileFactory.cpp"

Map::Map(std::string mapDefinition, std::map<std::pair<int,int>, Location> portals)
{
    buildMap(mapDefinition, portals);
}

void Map::buildMap(std::string mapDefinition, std::map<std::pair<int,int>, Location> portals)
{
    std::ifstream world(mapDefinition);
    int y = 0;
    for(std::string line; getline(world, line);)
    {
        std::stringstream ss(line);
        std::vector<GameTile *> row;
        int x = 0;
        for (int i; ss >> i;) {
            bool isPortal = portals.find(std::make_pair(x, y)) != portals.end();
            Location portalLocation;
            if (isPortal)
            {
                portalLocation = portals[std::make_pair(x, y)];
            }
            GameTile *tile = GameTileFactory::getTile(i, isPortal, portalLocation);
            row.push_back(tile);
            if (ss.peek() == ' ')
                ss.ignore();
            x++;
        }
        tiles.push_back(row);
        y++;
    }
}