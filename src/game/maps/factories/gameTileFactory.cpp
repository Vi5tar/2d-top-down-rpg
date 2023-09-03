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
    tileDataMap[10] = {"src/game/assets/16x16Tiles/dw-grass.png", true};
    tileDataMap[11] = {"src/game/assets/16x16Tiles/dw-trees.png", true};
    tileDataMap[12] = {"src/game/assets/16x16Tiles/dw-desert.png", true};
    tileDataMap[13] = {"src/game/assets/16x16Tiles/dw-hill.png", true};
    tileDataMap[14] = {"src/game/assets/16x16Tiles/dw-mountain.png", false};
    tileDataMap[17] = {"src/game/assets/16x16Tiles/dw-bridge.png", true};
    tileDataMap[18] = {"src/game/assets/16x16Tiles/dw-grassCave.png", true};
    tileDataMap[19] = {"src/game/assets/16x16Tiles/dw-grassStairs.png", true};
    tileDataMap[20] = {"src/game/assets/16x16Tiles/dw-swamp.png", true};
    tileDataMap[21] = {"src/game/assets/16x16Tiles/dw-water.png", false};
    tileDataMap[22] = {"src/game/assets/16x16Tiles/dw-nBeach.png", false};
    tileDataMap[23] = {"src/game/assets/16x16Tiles/dw-eBeach.png", false};
    tileDataMap[24] = {"src/game/assets/16x16Tiles/dw-sBeach.png", false};
    tileDataMap[25] = {"src/game/assets/16x16Tiles/dw-wBeach.png", false};
    tileDataMap[26] = {"src/game/assets/16x16Tiles/dw-neBeach.png", false};
    tileDataMap[27] = {"src/game/assets/16x16Tiles/dw-seBeach.png", false};
    tileDataMap[28] = {"src/game/assets/16x16Tiles/dw-swBeach.png", false};
    tileDataMap[29] = {"src/game/assets/16x16Tiles/dw-nwBeach.png", false};
    tileDataMap[30] = {"src/game/assets/16x16Tiles/dw-wneBeach.png", false};
    tileDataMap[31] = {"src/game/assets/16x16Tiles/dw-nesBeach.png", false};
    tileDataMap[32] = {"src/game/assets/16x16Tiles/dw-wseBeach.png", false};
    tileDataMap[33] = {"src/game/assets/16x16Tiles/dw-nwsBeach.png", false};
    tileDataMap[34] = {"src/game/assets/16x16Tiles/dw-nsBeach.png", false};
    tileDataMap[35] = {"src/game/assets/16x16Tiles/dw-weBeach.png", false};
    tileDataMap[40] = {"src/game/assets/16x16Tiles/dw-castle.png", true};
    tileDataMap[41] = {"src/game/assets/16x16Tiles/dw-town.png", true};
    tileDataMap[50] = {"src/game/assets/16x16Tiles/dw-brick.png", false};
    tileDataMap[51] = {"src/game/assets/16x16Tiles/dw-redBrickFloor.png", true};
    tileDataMap[52] = {"src/game/assets/16x16Tiles/dw-electricFloor.png", true};
    tileDataMap[53] = {"src/game/assets/16x16Tiles/dw-door.png", false};
    tileDataMap[54] = {"src/game/assets/16x16Tiles/dw-desk.png", false};
    tileDataMap[55] = {"src/game/assets/16x16Tiles/dw-treasureChest.png", true};
    tileDataMap[56] = {"src/game/assets/16x16Tiles/dw-brickStairsUp.png", true};
    tileDataMap[57] = {"src/game/assets/16x16Tiles/dw-brickStairsDown.png", true};
    tileDataMap[58] = {"src/game/assets/16x16Tiles/dw-greyBrickWall.png", false};
    
    TileData tileData = tileDataMap[tileNumber];
    if (isPortal)
        return new Portal(tileData.texturePath, tileData.walkable, portalDestination);
    else
        return new GameTile(tileData.texturePath, tileData.walkable);
}