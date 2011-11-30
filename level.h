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

    void SendBeam(QLineF beam, QPolygonF& beamPath);

    static void LoadMainLevel(GraphWidget* graph_widget, const Level& level);
};

#endif // LEVEL_H
