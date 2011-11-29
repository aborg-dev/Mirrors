#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "level.h"

class LevelManager
{
public:
    LevelManager();

    int GetLevel(int index, Level& level);

    int ReadLevel(const QString& file_name, Level& level);

    int WriteLevel(const QString& file_name, const Level& level);

    void AddLevel(const Level& level);

    Level create_test_level();
};

#endif // LEVELMANAGER_H
