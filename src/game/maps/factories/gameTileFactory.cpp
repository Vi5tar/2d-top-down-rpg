#include "gameTileFactory.h"
#include "../tiles/portal.cpp"
#include "../../../windowConfig.h"

GameTile *GameTileFactory::getTile(int tileNumber, bool isPortal, Location portalDestination)
{
    struct TileData
    {
        std::string texturePath;
        bool walkable;
    };
    
    std::map<int, TileData> tileDataMap;
    tileDataMap[10] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-grass.png", true};
    tileDataMap[11] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-trees.png", true};
    tileDataMap[12] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-desert.png", true};
    tileDataMap[13] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-hill.png", true};
    tileDataMap[14] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-mountain.png", false};
    tileDataMap[17] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-bridge.png", true};
    tileDataMap[18] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-grassCave.png", true};
    tileDataMap[19] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-grassStairs.png", true};
    tileDataMap[20] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-swamp.png", true};
    tileDataMap[21] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-water.png", false};
    tileDataMap[22] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-nBeach.png", false};
    tileDataMap[23] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-eBeach.png", false};
    tileDataMap[24] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-sBeach.png", false};
    tileDataMap[25] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-wBeach.png", false};
    tileDataMap[26] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-neBeach.png", false};
    tileDataMap[27] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-seBeach.png", false};
    tileDataMap[28] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-swBeach.png", false};
    tileDataMap[29] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-nwBeach.png", false};
    tileDataMap[30] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-wneBeach.png", false};
    tileDataMap[31] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-nesBeach.png", false};
    tileDataMap[32] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-wseBeach.png", false};
    tileDataMap[33] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-nwsBeach.png", false};
    tileDataMap[34] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-nsBeach.png", false};
    tileDataMap[35] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-weBeach.png", false};
    tileDataMap[40] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-castle.png", true};
    tileDataMap[41] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-town.png", true};
    tileDataMap[50] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-brick.png", false};
    tileDataMap[51] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-redBrickFloor.png", true};
    tileDataMap[52] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-electricFloor.png", true};
    tileDataMap[53] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-door.png", false};
    tileDataMap[54] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-desk.png", false};
    tileDataMap[55] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-treasureChest.png", true};
    tileDataMap[56] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-brickStairsUp.png", true};
    tileDataMap[57] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-brickStairsDown.png", true};
    tileDataMap[58] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-greyBrickWall.png", false};
    tileDataMap[59] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-armorySign.png", false};
    tileDataMap[60] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-innSign.png", false};
    tileDataMap[61] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-greyBrickWall.png", true};
    tileDataMap[62] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-black.png", true};
    tileDataMap[63] = {TILE_DIRECTORY + "/" + AESTHETIC_PREFIX + "-black.png", false};
    
    TileData tileData = tileDataMap[tileNumber];
    if (isPortal)
        return new Portal(tileData.texturePath, tileData.walkable, portalDestination);
    else
        return new GameTile(tileData.texturePath, tileData.walkable);
}