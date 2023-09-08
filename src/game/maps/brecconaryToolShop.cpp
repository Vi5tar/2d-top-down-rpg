#include "brecconaryToolShop.h"

BrecconaryToolShop::BrecconaryToolShop()
{
    name = MapName::BRECCONARY_TOOL_SHOP;
    layout = {
        {50,62,50,50,50,50,},
        {50,51,51,50,51,50,},
        {50,51,51,54,51,50,},
        {50,51,51,50,51,50,},
        {50,50,50,50,50,50,},
    };
    portals = {
        {{1, 0}, {MapName::BRECCONARY, sf::Vector2u(23, 24), Direction::UP}}
    };
};