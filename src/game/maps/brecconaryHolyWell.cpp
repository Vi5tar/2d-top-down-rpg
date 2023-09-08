#include "brecconaryHolyWell.h"

BrecconaryHolyWell::BrecconaryHolyWell()
{
    name = MapName::BRECCONARY_HOLY_WELL;
    layout = {
        {50,50,50,50,50,50,50,50,},
        {50,51,51,50,51,21,21,50,},
        {50,51,51,54,51,21,21,50,},
        {50,51,51,50,51,21,21,50,},
        {50,62,50,50,50,50,50,50,},
    };
    portals = {
        {{1, 4}, {MapName::BRECCONARY, sf::Vector2u(22, 7), Direction::DOWN}}
    };
};