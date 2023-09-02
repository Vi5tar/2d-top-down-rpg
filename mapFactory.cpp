#include "mapFactory.h"
#include "map.cpp"

Map MapFactory::getMap(MapName mapName)
{
    switch (mapName)
    {
    case MapName::WORLD:
    {
        std::map<std::pair<int, int>, Location> portals;
        portals.insert(std::make_pair(std::make_pair(44, 51), Location(MapName::TANTAGEL, sf::Vector2u(11, 30), Direction::UP)));
        
        return Map("dw-world-map.txt", portals);
    }
    case MapName::TANTAGEL:
    {
        std::map<std::pair<int, int>, Location> portals;
        for (int x = 0; x < 30; x++)
        {
            portals.insert(std::make_pair(std::make_pair(x, 0), Location(MapName::WORLD, sf::Vector2u(44, 51), Direction::DOWN)));
            portals.insert(std::make_pair(std::make_pair(x, 31), Location(MapName::WORLD, sf::Vector2u(44, 51), Direction::DOWN)));
        }
        return Map("dw-tantagel-castle-map.txt", portals);
    }
    }
}