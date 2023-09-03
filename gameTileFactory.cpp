#include "gameTileFactory.h"
#include "portal.h"

GameTile *GameTileFactory::getTile(int tileNumber, bool isPortal, Location portalDestination)
{
    struct TileData
    {
        std::string texturePath;
        bool walkable;
    };
    
    std::map<int, TileData> tileDataMap;
    tileDataMap[10] = {"assets/16x16Tiles/dw-grass.png", true};
    tileDataMap[11] = {"assets/16x16Tiles/dw-trees.png", true};
    tileDataMap[12] = {"assets/16x16Tiles/dw-desert.png", true};
    tileDataMap[13] = {"assets/16x16Tiles/dw-hill.png", true};
    tileDataMap[14] = {"assets/16x16Tiles/dw-mountain.png", false};
    tileDataMap[17] = {"assets/16x16Tiles/dw-bridge.png", true};
    tileDataMap[18] = {"assets/16x16Tiles/dw-grassCave.png", true};
    tileDataMap[19] = {"assets/16x16Tiles/dw-grassStairs.png", true};
    tileDataMap[20] = {"assets/16x16Tiles/dw-swamp.png", true};
    tileDataMap[21] = {"assets/16x16Tiles/dw-water.png", false};
    tileDataMap[22] = {"assets/16x16Tiles/dw-nBeach.png", false};
    tileDataMap[23] = {"assets/16x16Tiles/dw-eBeach.png", false};
    tileDataMap[24] = {"assets/16x16Tiles/dw-sBeach.png", false};
    tileDataMap[25] = {"assets/16x16Tiles/dw-wBeach.png", false};
    tileDataMap[26] = {"assets/16x16Tiles/dw-neBeach.png", false};
    tileDataMap[27] = {"assets/16x16Tiles/dw-seBeach.png", false};
    tileDataMap[28] = {"assets/16x16Tiles/dw-swBeach.png", false};
    tileDataMap[29] = {"assets/16x16Tiles/dw-nwBeach.png", false};
    tileDataMap[30] = {"assets/16x16Tiles/dw-wneBeach.png", false};
    tileDataMap[31] = {"assets/16x16Tiles/dw-nesBeach.png", false};
    tileDataMap[32] = {"assets/16x16Tiles/dw-wseBeach.png", false};
    tileDataMap[33] = {"assets/16x16Tiles/dw-nwsBeach.png", false};
    tileDataMap[34] = {"assets/16x16Tiles/dw-nsBeach.png", false};
    tileDataMap[35] = {"assets/16x16Tiles/dw-weBeach.png", false};
    tileDataMap[40] = {"assets/16x16Tiles/dw-castle.png", true};
    tileDataMap[41] = {"assets/16x16Tiles/dw-town.png", true};
    tileDataMap[50] = {"assets/16x16Tiles/dw-brick.png", false};
    tileDataMap[51] = {"assets/16x16Tiles/dw-redBrickFloor.png", true};
    tileDataMap[52] = {"assets/16x16Tiles/dw-electricFloor.png", true};
    tileDataMap[53] = {"assets/16x16Tiles/dw-door.png", false};
    tileDataMap[54] = {"assets/16x16Tiles/dw-desk.png", false};
    tileDataMap[55] = {"assets/16x16Tiles/dw-treasureChest.png", true};
    tileDataMap[56] = {"assets/16x16Tiles/dw-brickStairsUp.png", true};
    tileDataMap[57] = {"assets/16x16Tiles/dw-brickStairsDown.png", true};
    tileDataMap[58] = {"assets/16x16Tiles/dw-greyBrickWall.png", false};
    
    TileData tileData = tileDataMap[tileNumber];
    if (isPortal)
        return new Portal(tileData.texturePath, tileData.walkable, portalDestination);
    else
        return new GameTile(tileData.texturePath, tileData.walkable);
}