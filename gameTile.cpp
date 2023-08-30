#include "gameTile.h"

GameTile::GameTile(std::string textureName, bool walkable, bool exit)
{
    if (!setUpSprite(textureName))
    {
        return;
    }
    this->walkable = walkable;
    isExit = exit;
}

bool GameTile::setUpSprite(std::string textureName)
{
    if (!texture.loadFromFile(textureName))
        return false;

    sprite.setTexture(texture);
    sprite.setScale(3, 3);

    return true;
}

bool GameTile::isWalkable()
{
    return walkable;
}

GameTile *GameTile::getTile(int key)
{
    if (key == 10)
        return new GameTile("assets/16x16Tiles/dw-grass.png", true, false);
    if (key == 11)
        return new GameTile("assets/16x16Tiles/dw-trees.png", true, false);
    if (key == 12)
        return new GameTile("assets/16x16Tiles/dw-desert.png", true, false);
    if (key == 13)
        return new GameTile("assets/16x16Tiles/dw-hill.png", true, false);
    if (key == 14)
        return new GameTile("assets/16x16Tiles/dw-mountain.png", false, false);
    if (key == 17)
        return new GameTile("assets/16x16Tiles/dw-bridge.png", true, true);
    if (key == 18)
        return new GameTile("assets/16x16Tiles/dw-grassCave.png", true, true);    
    if (key == 19)
        return new GameTile("assets/16x16Tiles/dw-grassStairs.png", true, true);
    if (key == 20)
        return new GameTile("assets/16x16Tiles/dw-swamp.png", true, false);
    if (key == 21)
        return new GameTile("assets/16x16Tiles/dw-water.png", false, false);
    if (key == 22)
        return new GameTile("assets/16x16Tiles/dw-nBeach.png", false, false);
    if (key == 23)
        return new GameTile("assets/16x16Tiles/dw-eBeach.png", false, false);
    if (key == 24)
        return new GameTile("assets/16x16Tiles/dw-sBeach.png", false, false);
    if (key == 25)
        return new GameTile("assets/16x16Tiles/dw-wBeach.png", false, false);
    if (key == 26)
        return new GameTile("assets/16x16Tiles/dw-neBeach.png", false, false);
    if (key == 27)
        return new GameTile("assets/16x16Tiles/dw-seBeach.png", false, false);
    if (key == 28)
        return new GameTile("assets/16x16Tiles/dw-swBeach.png", false, false);
    if (key == 29)
        return new GameTile("assets/16x16Tiles/dw-nwBeach.png", false, false);
    if (key == 30)
        return new GameTile("assets/16x16Tiles/dw-wneBeach.png", false, false);
    if (key == 31)
        return new GameTile("assets/16x16Tiles/dw-nesBeach.png", false, false);
    if (key == 32)
        return new GameTile("assets/16x16Tiles/dw-wseBeach.png", false, false);
    if (key == 33)
        return new GameTile("assets/16x16Tiles/dw-nwsBeach.png", false, false);
    if (key == 34)
        return new GameTile("assets/16x16Tiles/dw-nsBeach.png", false, false);
    if (key == 35)
        return new GameTile("assets/16x16Tiles/dw-weBeach.png", false, false);
    if (key == 40)
        return new GameTile("assets/16x16Tiles/dw-castle.png", true, true);
    if (key == 41)
        return new GameTile("assets/16x16Tiles/dw-town.png", true, true);
    if (key == 50)
        return new GameTile("assets/16x16Tiles/dw-brick.png", false, true);
    if (key == 51)
        return new GameTile("assets/16x16Tiles/dw-redBrickFloor.png", true, true);
    if (key == 52)
        return new GameTile("assets/16x16Tiles/dw-electricFloor.png", true, true);
    if (key == 53)
        return new GameTile("assets/16x16Tiles/dw-door.png", false, true);
    if (key == 54)
        return new GameTile("assets/16x16Tiles/dw-desk.png", false, true);
    if (key == 55)
        return new GameTile("assets/16x16Tiles/dw-treasureChest.png", true, true);
    if (key == 56)
        return new GameTile("assets/16x16Tiles/dw-brickStairsUp.png", true, true);
    if (key == 57)
        return new GameTile("assets/16x16Tiles/dw-brickStairsDown.png", true, true);
    return new GameTile("", false, false);
}