#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QPointF>
#include <QLineF>
#include <QBitmap>

class GameObject
{
public:
    GameObject();
    GameObject(QPointF center, QPolygonF body);

    static const QString class_name_;
    QPointF center_;
    QPolygonF body_;

    virtual int reflectBeam(QLineF beam, QPolygonF * beamPath) { return -1; }

};

#endif // GAMEOBJECT_H
