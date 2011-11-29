#include "gameobject.h"

const QString GameObject::class_name_ = "GameObject";

GameObject::GameObject()
{
}

GameObject::GameObject(QPointF center, QPolygonF body)
{
  center_ = center;
  body_ = body;
}
