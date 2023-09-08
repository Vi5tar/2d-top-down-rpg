#include <fstream>
#include <sstream>
#include "map.h"
#include "factories/gameTileFactory.cpp"

Map::Map(MapName name, std::vector<std::vector<int>> layout, std::map<std::pair<int,int>, Location> portals)
{
    this->name = name;
}

void Map::loadTiles(sf::IntRect loadArea)
{
    if (loadArea.left < 0)
        loadArea.left = 0;
    if (loadArea.top < 0)
        loadArea.top = 0;

    for(int y = loadArea.top; y < loadArea.top + loadArea.height && y < layout.size(); y++)
    {
        for(int x = loadArea.left; x < loadArea.left + loadArea.width && x < layout[y].size(); x++)
        {
            bool isPortal = portals.find(std::make_pair(x, y)) != portals.end();
            Location portalLocation;
            if (isPortal)
            {
                portalLocation = portals[std::make_pair(x, y)];
            }
            if (tiles.find({x, y}) == tiles.end())
            {
                GameTile *tile = GameTileFactory::getTile(layout[y][x], isPortal, portalLocation);
                tiles.insert({{x, y}, tile});
            }
        }
    }
}