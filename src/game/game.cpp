#include "game.h"
#include "maps/factories/mapFactory.cpp"
#include "player/player.cpp"

Game::Game(Location initialLocation)
{
    player = new Player();
    setPlayerLocation(initialLocation);
}

bool Game::canMove(Player *player, Direction direction)
{
    int playerX = player->getX();
    int playerY = player->getY();
    if (direction == Direction::LEFT)
    {
        if (playerX - 1 >= 0)
        {
            if (currentMap.tiles[{playerX - 1, playerY}]->isWalkable())
                return true;
        }
    }
    else if (direction == Direction::RIGHT)
    {
        if (playerX + 1 < currentMap.layout[playerY].size())
        {
            if (currentMap.tiles[{playerX + 1, playerY}]->isWalkable())
                return true;
        }
    }
    else if (direction == Direction::UP)
    {
        if (playerY - 1 >= 0)
        {
            if (currentMap.tiles[{playerX, playerY - 1}]->isWalkable())
                return true;
        }
    }
    else if (direction == Direction::DOWN)
    {
        if (playerY + 1 < currentMap.layout.size())
        {
            if (currentMap.tiles[{playerX, playerY + 1}]->isWalkable())
                return true;
        }
    }
    return false;
}

void Game::movePlayerLeft()
{
    player->setOrientation(Direction::LEFT);
    if (canMove(player, Direction::LEFT))
        player->moveLeft();
        loadUpcomingTiles();
}

void Game::movePlayerRight()
{
    player->setOrientation(Direction::RIGHT);
    if (canMove(player, Direction::RIGHT))
        player->moveRight();
        loadUpcomingTiles();
}

void Game::movePlayerUp()
{
    player->setOrientation(Direction::UP);
    if (canMove(player, Direction::UP))
        player->moveUp();
        loadUpcomingTiles();
}

void Game::movePlayerDown()
{
    player->setOrientation(Direction::DOWN);
    if (canMove(player, Direction::DOWN))
        player->moveDown();
        loadUpcomingTiles();
}

void Game::setCurrentMap(MapName mapName)
{
    currentMap = MapFactory::getMap(mapName);
}

void Game::setPlayerLocation(Location location)
{
    setCurrentMap(location.mapName);
    currentMap.loadTiles(getLoadArea(location.position.x, location.position.y));
    player->setLocation(location);
}

void Game::loadUpcomingTiles()
{
    currentMap.loadTiles(getLoadArea(player->getX(), player->getY()));
}

sf::IntRect Game::getLoadArea(int x, int y)
{
    return sf::IntRect(x - (WINDOW_TILES_WIDE / 2), y - (WINDOW_TILES_HIGH / 2), WINDOW_TILES_WIDE, WINDOW_TILES_HIGH);
}

void Game::saveState()
{
    std::ofstream saveFile;
    saveFile.open("save.txt");
    saveFile << (int)currentMap.name << std::endl;
    saveFile << player->getX() << std::endl;
    saveFile << player->getY() << std::endl;
    saveFile << (int)player->getOrientation() << std::endl;
    saveFile.close();
}

void Game::loadState()
{
    std::ifstream saveFile;
    saveFile.open("save.txt");
    int mapName;
    int playerX;
    int playerY;
    int playerOrientation;
    saveFile >> mapName;
    saveFile >> playerX;
    saveFile >> playerY;
    saveFile >> playerOrientation;
    saveFile.close();
    setPlayerLocation(Location((MapName)mapName, sf::Vector2u(playerX, playerY), (Direction)playerOrientation));
}
