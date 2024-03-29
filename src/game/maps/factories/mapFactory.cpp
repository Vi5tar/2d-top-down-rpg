#include "mapFactory.h"
#include "../map.cpp"
#include "../world.cpp"
#include "../tantagel.cpp"
#include "../tantagelThroneRoom.cpp"
#include "../tantagelCellar.cpp"
#include "../brecconary.cpp"
#include "../brecconaryToolShop.cpp"
#include "../brecconaryHolyWell.cpp"
#include "../erdricksCave1.cpp"
#include "../erdricksCave2.cpp"
#include "../garinham.cpp"
#include "../garinhamInterior.cpp"
#include "../garinsGrave1.cpp"
#include "../garinsGrave2.cpp"
#include "../garinsGrave3.cpp"
#include "../garinsGrave4.cpp"
#include "../kol.cpp"

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
    case MapName::BRECCONARY_TOOL_SHOP:
        return BrecconaryToolShop();
    case MapName::BRECCONARY_HOLY_WELL:
        return BrecconaryHolyWell();
    case MapName::ERDRICKS_CAVE_1:
        return ErdricksCave1();
    case MapName::ERDRICKS_CAVE_2:
        return ErdricksCave2();
    case MapName::GARINHAM:
        return Garinham();
    case MapName::GARINHAM_INTERIOR:
        return GarinhamInterior();
    case MapName::GARINS_GRAVE_1:
        return GarinsGrave1();
    case MapName::GARINS_GRAVE_2:
        return GarinsGrave2();
    case MapName::GARINS_GRAVE_3:
        return GarinsGrave3();
    case MapName::GARINS_GRAVE_4:
        return GarinsGrave4();
    case MapName::KOL:
        return Kol();
    }
}