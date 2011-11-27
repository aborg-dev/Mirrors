#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QPointF>
#include <QLineF>
#include <QBitmap>

class GameObject
{
public:
    GameObject();
    GameObject(QPointF center, QBitmap image);

    QPointF center_;
    QBitmap image_;

    virtual int reflectBeam(QLineF beam, QLineF * resultBeam) const;

};

#endif // GAMEOBJECT_H
