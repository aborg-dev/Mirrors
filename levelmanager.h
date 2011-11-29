#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "level.h"

class LevelManager
{
public:
    LevelManager();

    bool GetLevel(int index, Level & level);

    bool ReadLevel(const QString & file, Level & level);

    void WriteLevel(const Level & level);

    void AddLevel(const Level & level);
};

#endif // LEVELMANAGER_H
