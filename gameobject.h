#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QPointF>
#include <QLineF>
#include <QBitmap>

class GameObject
{
public:
    GameObject();
    GameObject(QPointF center, QPolygonF skeleton);

    static const QString class_name_ = "GameObject";
    QPointF center_;
    QPolygonF skeleton_;

    virtual int reflectBeam(QLineF beam, QLineF * resultBeam) const;

};

#endif // GAMEOBJECT_H
