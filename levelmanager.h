#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "level.h"

class LevelManager
{
public:
    LevelManager();

    Level GetLevel(int index);
};

#endif // LEVELMANAGER_H
