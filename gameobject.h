#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsItem>
#include <QPointF>

class GraphWidget;

class GameObject : public QGraphicsItem
{
public:
    GameObject();
    GameObject(QPointF center, QPolygonF body);

    QPointF center_;
    QPolygonF body_;
    GraphWidget *graph_widget_;

    void SetGraphWidget(GraphWidget* graph_widget);

    QRectF boundingRect() const;

    QPainterPath shape() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual int reflectBeam(QLineF beam, QPolygonF * beamPath) { return -1; }

    virtual QString class_name() const
    {
      return QString("GameObject");
    }

};

#endif // GAMEOBJECT_H
