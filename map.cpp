#include <fstream>
#include <sstream>
#include "map.h"
#include "gameTileFactory.cpp"

Map::Map(MapName name, std::vector<std::vector<int>> layout, std::map<std::pair<int,int>, Location> portals)
{
    this->name = name;
    build(layout, portals);
}

void Map::build(std::vector<std::vector<int>> mapLayout, std::map<std::pair<int,int>, Location> portals)
{
    for(int y = 0; y < mapLayout.size(); y++)
    {
        std::vector<GameTile *> row;
        for(int x = 0; x < mapLayout[y].size(); x++)
        {
            bool isPortal = portals.find(std::make_pair(x, y)) != portals.end();
            Location portalLocation;
            if (isPortal)
            {
                portalLocation = portals[std::make_pair(x, y)];
            }
            GameTile *tile = GameTileFactory::getTile(mapLayout[y][x], isPortal, portalLocation);
            row.push_back(tile);
        }
        tiles.push_back(row);
    }
}