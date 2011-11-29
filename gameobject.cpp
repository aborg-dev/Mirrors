#include "gameobject.h"

#include <QPainter>
#include <QPainterPath>

const QString GameObject::class_name_ = "GameObject";

GameObject::GameObject()
{
}

GameObject::GameObject(QPointF center, QPolygonF body)
{
  center_ = center;
  body_ = body;
}

void GameObject::SetGraphWidget(GraphWidget* graph_widget)
{
  graph_widget_ = graph_widget;
  setFlag(ItemIsMovable);
  setFlag(ItemSendsGeometryChanges);
  setCacheMode(DeviceCoordinateCache);
  setZValue(-1);
}

void GameObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
  painter->save();
  painter->translate(center_);
  painter->setBrush(Qt::darkGray);
  painter->setPen(QPen(Qt::black, 0));
  painter->drawPolygon(body_);
  painter->restore();
}

QRectF GameObject::boundingRect() const
{
    return body_.boundingRect();
}

QPainterPath GameObject::shape() const
{
    QPainterPath path;
    path.addPolygon(body_);
    return path;
}
