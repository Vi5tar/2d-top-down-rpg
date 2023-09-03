#include "mapFactory.h"
#include "map.cpp"
#include "world.cpp"
#include "tantagel.cpp"
#include "tantagelThroneRoom.cpp"

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
    }
}