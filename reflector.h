#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "gameobject.h"

class Reflector : public GameObject
{
public:
    Reflector();

    QString class_name() const
    {
      return QString("Reflector");
    }
};

#endif // REFLECTOR_H
