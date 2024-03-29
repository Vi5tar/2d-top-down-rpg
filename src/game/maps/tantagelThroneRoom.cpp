#include "tantagelThroneRoom.h"

TantagelThroneRoom::TantagelThroneRoom()
{
    name = MapName::TANTAGEL_THRONE_ROOM;
    layout = {
        {58,58,58,58,58,58,58,58,58,58,58,58},
        {58,50,50,50,50,50,50,50,50,50,50,58},
        {58,50,51,51,51,51,51,51,51,51,50,58},
        {58,50,51,54,54,54,54,54,54,51,50,58},
        {58,50,51,54,51,54,54,51,54,51,50,58},
        {58,50,51,51,51,51,51,51,51,51,50,58},
        {58,50,51,51,51,51,51,51,51,51,50,58},
        {58,50,51,51,51,51,51,51,51,51,50,58},
        {58,50,50,50,50,51,50,50,50,50,50,58},
        {58,50,51,51,51,51,51,51,51,57,50,58},
        {58,50,50,50,50,50,50,50,50,50,50,58},
        {58,58,58,58,58,58,58,58,58,58,58,58},
    };
    portals = {
        {{9, 9}, Location(MapName::TANTAGEL, sf::Vector2u(7, 8), Direction::RIGHT)},
    };
}