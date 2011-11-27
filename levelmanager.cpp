#include "levelmanager.h"

LevelManager::LevelManager()
{
}

Level LevelManager::GetLevel(int index)
{
  return new Level();
}
