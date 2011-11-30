#include "absorber.h"

#include <QPainter>

Absorber::Absorber()
{
}

void Absorber::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
  painter->save();
  painter->translate(center_);
  painter->setBrush(Qt::blue);
  painter->setPen(QPen(Qt::black, 0));
  painter->drawPolygon(body_);
  painter->restore();
}


int Absorber::ReflectBeam(const QLineF& beam, QPolygonF& beamPath) const
{
  return 0;
}
