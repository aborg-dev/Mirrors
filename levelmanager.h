#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "level.h"

class LevelManager
{
public:
    LevelManager();

    Level GetLevel(int index);
    void AddLevel(const Level & level);
};

#endif // LEVELMANAGER_H
