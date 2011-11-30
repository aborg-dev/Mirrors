#ifndef ABSORBER_H
#define ABSORBER_H

#include "gameobject.h"

class Absorber : public GameObject
{
public:
    Absorber();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int ReflectBeam(const QLineF& beam, QPolygonF& beamPath, qreal& distance) const;

    QString class_name() const
    {
      return QString("Absorber");
    }
};

#endif // ABSORBER_H
