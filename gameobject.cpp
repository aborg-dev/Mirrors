#include "gameobject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(QPointF center, QBitmap image)
{
  center_ = center;
  image_ = image;
}

int GameObject::reflectBeam(QLineF beam, QLineF *resultBeam) const
{
  return 0;
}
