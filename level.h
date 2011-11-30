#ifndef LEVEL_H
#define LEVEL_H

#include "gameobject.h"
#include "reflector.h"
#include "absorber.h"

class GraphWidget;

class Level
{
public:
    Level();

    QString name_;
    QVector<GameObject*> objects_;
    QGraphicsLineItem* beam_item_;

    void SendBeam(QGraphicsScene& scene, const QLineF& beam);

    static void LoadMainLevel(GraphWidget* graph_widget, const Level& level);

    void RemoveLastBeam(QGraphicsScene& scene);
};

#endif // LEVEL_H
