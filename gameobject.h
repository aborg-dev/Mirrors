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

    QPointF offset_;
    QPolygonF body_;
    GraphWidget *graph_widget_;

    void SetGraphWidget(GraphWidget* graph_widget);

    virtual QRectF boundingRect() const;

    virtual QPainterPath shape() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    // 0 - No intersection
    // 1 - intersect
    // 2 - absorb
    // 3 - infinite cycle
    virtual int ReflectBeam(QLineF&, QPolygonF&, qreal&) const;

    virtual bool IntersectWithBeam(const QLineF& beam, QPointF& intersection_point, qreal& angle) const;

    virtual QString class_name() const
    {
      return QString("GameObject");
    }

};

#endif // GAMEOBJECT_H
