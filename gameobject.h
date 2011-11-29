#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsItem>
#include <QPointF>
#include <QLineF>

class GraphWidget;

class GameObject : public QGraphicsItem
{
public:
    GameObject();
    GameObject(QPointF center, QPolygonF body);

    static const QString class_name_;
    QPointF center_;
    QPolygonF body_;
    GraphWidget *graph_widget_;

    void SetGraphWidget(GraphWidget* graph_widget);

    QRectF boundingRect() const;

    QPainterPath shape() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual int reflectBeam(QLineF beam, QPolygonF * beamPath) { return -1; }

};

#endif // GAMEOBJECT_H
