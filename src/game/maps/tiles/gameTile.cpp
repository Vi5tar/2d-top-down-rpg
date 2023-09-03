#include "gameTile.h"
#include "../../../windowConfig.h"

GameTile::GameTile(std::string textureName, bool walkable)
{
    if (!setUpSprite(textureName))
    {
        return;
    }
    this->walkable = walkable;
}

bool GameTile::setUpSprite(std::string textureName)
{
    if (!texture.loadFromFile(textureName))
        return false;

    sprite.setTexture(texture);
    sprite.setScale(SCALE_X, SCALE_Y);

    return true;
}

bool GameTile::isWalkable()
{
    return walkable;
}

bool GameTile::isPortal()
{
    return false;
}