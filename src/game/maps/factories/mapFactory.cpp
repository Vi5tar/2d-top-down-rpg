#include "mapFactory.h"
#include "../map.cpp"
#include "../world.cpp"
#include "../tantagel.cpp"
#include "../tantagelThroneRoom.cpp"
#include "../tantagelCellar.cpp"
#include "../brecconary.cpp"

Map MapFactory::getMap(MapName mapName)
{
    switch (mapName)
    {
    case MapName::WORLD:
        return World();
    case MapName::TANTAGEL:
        return Tantagel();
    case MapName::TANTAGEL_THRONE_ROOM:
        return TantagelThroneRoom();
    case MapName::TANTAGEL_CELLAR:
        return TantagelCellar();
    case MapName::BRECCONARY:
        return Brecconary();
    }
}