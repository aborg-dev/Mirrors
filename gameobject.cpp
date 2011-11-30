#include "gameobject.h"

#include <QPainter>
#include <QPainterPath>
#include <QVector2D>

#include <iostream>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

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

bool GameObject::IntersectWithBeam(const QLineF &beam, QPointF &intersection_point, qreal &angle) const
{
  qreal nearest_length = 1e9;
  for(int i = 0; i < body_.size(); i++)
  {
    QLineF edge(body_.at(i), body_.at((i+1)%body_.size()));
    QPointF current_intersection;
    QLineF::IntersectType result = beam.intersect(edge, &current_intersection);
    if (result == 1 || result == 2)
    {
      QVector2D diff1 = QVector2D(edge.p1() - current_intersection), diff2 = QVector2D(edge.p2() - current_intersection);
      if ((diff1.x() * diff2.x() > 0) || (diff1.y() * diff2.y() > 0))
        continue;

      diff1 = QVector2D(current_intersection - beam.p1());
      diff2 = QVector2D(current_intersection - beam.p2());

      if (diff1.length() < diff2.length())
        continue;

      if (diff1.length() < nearest_length)
      {
        nearest_length = diff1.length();
        intersection_point = current_intersection;
        angle = edge.angleTo(beam);
      }

    }
  }
  return (nearest_length < 1e9);
}

int GameObject::ReflectBeam(QLineF &beam, QPolygonF& beamPath, qreal& distance) const
{
  beam.setLength(1);
  QPointF intersection_point;
  beamPath.clear();
  int iterations = 0;
  qreal angle = 0.0;
  beamPath.push_back(beam.p1());
  while (iterations < 1000 && IntersectWithBeam(beam, intersection_point, angle))
  {
    iterations++;
    if (iterations == 1)
      distance = QVector2D(beam.p1() - intersection_point).length();
    beamPath.push_back(intersection_point);
    beam.setP1(intersection_point);
    beam.setAngle(beam.angle() - 2*angle + 180);
    beam.setLength(1);
  }
  if (beamPath.size() == 1)
    return 0;
  if (iterations == 1000)
    return 3;
  return 1;
}
