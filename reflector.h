#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "gameobject.h"

class Reflector : public GameObject
{
public:
    Reflector();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QString class_name() const
    {
      return QString("Reflector");
    }

};

#endif // REFLECTOR_H
