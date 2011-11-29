#include "gameobject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(QPointF center, QPolygonF skeleton)
{
  center_ = center;
  skeleton_ = skeleton;
}

int GameObject::reflectBeam(QLineF beam, QPolygonF *beamPath) const
{
  return 0;
}
