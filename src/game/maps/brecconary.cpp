#include "brecconary.h"

Brecconary::Brecconary()
{
    name = MapName::BRECCONARY;
    layout = {
        {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,},
        {10,50,50,50,50,50,50,50,50,50,50,50,50,50,12,51,51,12,50,50,50,50,50,50,50,50,50,50,50,50,50,10,},
        {10,50,11,11,11,10,10,10,10,11,11,11,11,12,12,51,51,12,12,11,11,11,11,11,11,11,11,11,11,11,50,10,},
        {10,50,11,11,10,10,10,10,10,10,11,10,11,10,12,51,51,12,10,10,11,50,50,50,50,50,50,50,50,11,50,10,},
        {10,50,11,10,50,50,50,50,50,10,10,10,10,10,10,51,51,10,10,10,11,50,51,51,50,51,21,21,50,11,50,10,},
        {10,50,11,10,50,51,51,51,50,10,10,10,10,10,10,51,51,12,10,10,10,50,51,51,54,51,21,21,50,11,50,10,},
        {10,50,11,10,50,51,54,51,50,10,10,10,10,10,10,51,51,12,10,11,10,50,51,51,50,51,21,21,50,11,50,10,},
        {10,50,11,10,50,50,51,50,50,10,10,12,12,10,10,51,51,12,12,11,10,50,53,50,50,50,50,50,50,10,50,10,},
        {10,50,11,10,10,10,51,59,10,10,12,12,12,12,10,51,51,12,10,11,10,10,10,10,11,10,10,11,10,10,50,10,},
        {10,50,11,11,10,10,51,10,10,12,12,11,12,12,10,51,51,12,10,10,10,10,10,11,11,11,11,11,11,10,50,10,},
        {10,50,11,10,10,10,51,10,10,12,11,11,11,12,12,51,51,10,10,50,50,50,50,50,50,50,50,50,11,10,50,10,},
        {10,50,11,10,10,10,51,10,12,12,12,11,11,11,12,51,51,10,10,50,51,51,51,50,51,51,51,50,10,10,50,10,},
        {10,50,10,10,10,10,51,10,12,12,11,11,11,12,10,51,51,10,10,50,51,51,51,50,51,51,51,50,10,10,50,10,},
        {10,50,11,11,10,10,51,10,10,12,12,12,12,12,10,51,51,10,10,50,50,51,50,50,50,51,50,50,10,11,50,10,},
        {10,11,11,10,10,10,51,10,10,10,10,12,12,10,10,51,51,10,10,10,10,51,10,10,10,51,10,10,10,11,11,10,},
        {10,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,10,},
        {10,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,10,},
        {10,11,11,10,10,10,10,10,10,51,10,10,10,10,11,10,51,10,10,10,11,10,10,10,10,10,21,21,21,11,11,10,},
        {10,50,11,11,10,10,10,10,10,51,10,10,10,11,11,10,51,10,11,11,11,11,10,21,21,21,21,21,21,21,11,10,},
        {10,50,11,10,10,10,10,10,10,51,10,10,11,11,10,10,51,11,11,11,10,10,21,21,21,21,21,21,21,21,21,10,},
        {10,50,10,10,10,10,10,50,60,51,50,10,10,10,10,10,51,10,11,10,10,21,21,21,21,21,21,21,21,21,21,10,},
        {10,50,10,50,50,50,50,50,50,51,50,50,50,10,10,10,51,11,10,10,21,21,21,21,10,10,21,21,21,21,21,10,},
        {10,50,10,50,51,51,50,51,51,51,54,51,50,10,10,10,51,10,10,21,21,10,10,10,10,10,10,10,21,21,21,10,},
        {10,50,10,50,51,51,50,51,50,50,50,50,50,10,11,10,51,51,51,17,10,10,10,10,10,10,10,10,10,10,21,10,},
        {10,50,10,50,51,51,53,51,51,51,51,51,50,10,11,10,10,10,10,21,10,10,50,51,50,50,50,50,11,10,21,10,},
        {10,50,10,50,51,50,50,51,50,50,51,51,50,10,11,11,10,10,21,21,10,10,50,51,51,50,51,50,11,10,21,10,},
        {10,50,10,50,51,51,50,51,51,50,51,51,50,11,11,11,11,10,21,21,21,10,50,51,51,54,51,50,10,21,21,10,},
        {10,50,10,50,51,51,50,51,51,50,51,51,50,10,11,11,10,10,21,21,10,10,50,51,51,50,51,50,10,11,21,10,},
        {10,50,10,50,50,50,50,50,50,50,50,50,50,10,11,10,10,21,21,21,21,10,50,50,50,50,50,50,11,11,21,10,},
        {10,50,10,10,10,10,10,10,10,10,10,10,10,10,10,10,21,21,21,21,21,10,10,10,10,10,21,21,11,21,21,10,},
        {10,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,21,21,21,21,21,21,21,21,21,21,10,},
    };
    for (int y = 0; y < layout.size(); y++)
    {
        int xSize = layout[y].size();
        portals.insert({{0, y}, Location(MapName::WORLD, sf::Vector2u(49, 49), Direction::DOWN)});
        portals.insert({{xSize - 1, y}, Location(MapName::WORLD, sf::Vector2u(49, 49), Direction::DOWN)});
        for (int x = 0; x < xSize; x++)
        {
            portals.insert({{x, 0}, Location(MapName::WORLD, sf::Vector2u(49, 49), Direction::DOWN)}); 
        }
    };
    build(layout, portals);
}