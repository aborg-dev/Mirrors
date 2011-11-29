    #ifndef LEVEL_H
#define LEVEL_H

#include "gameobject.h"

class Level
{
public:
    Level();

    QString name_;
    QVector<GameObject*> objects_;

};

#endif // LEVEL_H
