#include "gameTileFactory.h"
#include "../tiles/portal.cpp"

GameTile *GameTileFactory::getTile(int tileNumber, bool isPortal, Location portalDestination)
{
    struct TileData
    {
        std::string texturePath;
        bool walkable;
    };
    
    std::map<int, TileData> tileDataMap;
    tileDataMap[10] = {"src/game/assets/8x8Tiles/ds-grass.png", true};
    tileDataMap[11] = {"src/game/assets/8x8Tiles/ds-trees.png", true};
    tileDataMap[12] = {"src/game/assets/8x8Tiles/ds-desert.png", true};
    tileDataMap[13] = {"src/game/assets/8x8Tiles/ds-hill.png", true};
    tileDataMap[14] = {"src/game/assets/8x8Tiles/ds-mountain.png", false};
    tileDataMap[17] = {"src/game/assets/8x8Tiles/ds-bridge.png", true};
    tileDataMap[18] = {"src/game/assets/8x8Tiles/ds-grassCave.png", true};
    tileDataMap[19] = {"src/game/assets/8x8Tiles/ds-grassStairs.png", true};
    tileDataMap[20] = {"src/game/assets/8x8Tiles/ds-swamp.png", true};
    tileDataMap[21] = {"src/game/assets/8x8Tiles/ds-water.png", false};
    tileDataMap[22] = {"src/game/assets/8x8Tiles/ds-nBeach.png", false};
    tileDataMap[23] = {"src/game/assets/8x8Tiles/ds-eBeach.png", false};
    tileDataMap[24] = {"src/game/assets/8x8Tiles/ds-sBeach.png", false};
    tileDataMap[25] = {"src/game/assets/8x8Tiles/ds-wBeach.png", false};
    tileDataMap[26] = {"src/game/assets/8x8Tiles/ds-neBeach.png", false};
    tileDataMap[27] = {"src/game/assets/8x8Tiles/ds-seBeach.png", false};
    tileDataMap[28] = {"src/game/assets/8x8Tiles/ds-swBeach.png", false};
    tileDataMap[29] = {"src/game/assets/8x8Tiles/ds-nwBeach.png", false};
    tileDataMap[30] = {"src/game/assets/8x8Tiles/ds-wneBeach.png", false};
    tileDataMap[31] = {"src/game/assets/8x8Tiles/ds-nesBeach.png", false};
    tileDataMap[32] = {"src/game/assets/8x8Tiles/ds-wseBeach.png", false};
    tileDataMap[33] = {"src/game/assets/8x8Tiles/ds-nwsBeach.png", false};
    tileDataMap[34] = {"src/game/assets/8x8Tiles/ds-nsBeach.png", false};
    tileDataMap[35] = {"src/game/assets/8x8Tiles/ds-weBeach.png", false};
    tileDataMap[40] = {"src/game/assets/8x8Tiles/ds-castle.png", true};
    tileDataMap[41] = {"src/game/assets/8x8Tiles/ds-town.png", true};
    tileDataMap[50] = {"src/game/assets/8x8Tiles/ds-brick.png", false};
    tileDataMap[51] = {"src/game/assets/8x8Tiles/ds-redBrickFloor.png", true};
    tileDataMap[52] = {"src/game/assets/8x8Tiles/ds-electricFloor.png", true};
    tileDataMap[53] = {"src/game/assets/8x8Tiles/ds-door.png", false};
    tileDataMap[54] = {"src/game/assets/8x8Tiles/ds-desk.png", false};
    tileDataMap[55] = {"src/game/assets/8x8Tiles/ds-treasureChest.png", true};
    tileDataMap[56] = {"src/game/assets/8x8Tiles/ds-brickStairsUp.png", true};
    tileDataMap[57] = {"src/game/assets/8x8Tiles/ds-brickStairsDown.png", true};
    tileDataMap[58] = {"src/game/assets/8x8Tiles/ds-greyBrickWall.png", false};
    tileDataMap[59] = {"src/game/assets/8x8Tiles/ds-armorySign.png", false};
    tileDataMap[60] = {"src/game/assets/8x8Tiles/ds-innSign.png", false};
    tileDataMap[61] = {"src/game/assets/8x8Tiles/ds-greyBrickWall.png", true};
    tileDataMap[62] = {"src/game/assets/8x8Tiles/ds-black.png", true};
    
    TileData tileData = tileDataMap[tileNumber];
    if (isPortal)
        return new Portal(tileData.texturePath, tileData.walkable, portalDestination);
    else
        return new GameTile(tileData.texturePath, tileData.walkable);
}