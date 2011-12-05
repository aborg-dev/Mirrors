#include "reflector.h"

#include <QPainter>

Reflector::Reflector()
{
}

void Reflector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
  painter->save();
  //painter->translate(offset_);
  painter->setBrush(Qt::red);
  painter->setPen(QPen(Qt::black, 0));
  painter->drawPolygon(body_);
  painter->restore();
}
