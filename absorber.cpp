#include "absorber.h"

#include <QPainter>
#include <QVector2D>

Absorber::Absorber()
{
}

void Absorber::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
  painter->save();
  //painter->translate(offset_);
  painter->setBrush(Qt::blue);
  painter->setPen(QPen(Qt::black, 0));
  painter->drawPolygon(body_);
  painter->restore();
}


int Absorber::ReflectBeam(const QLineF& beam, QPolygonF&, qreal& distance) const
{
  QPointF point; qreal angle;
  if (IntersectWithBeam(beam, point, angle))
  {
    distance = QVector2D(beam.p1() - point).length();
    return 2;
  }
  return 0;
}
