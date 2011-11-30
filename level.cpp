#include "level.h"
#include "graphwidget.h"

#include <iostream>

Level::Level()
{
}

void Level::SendBeam(QLineF beam, QPolygonF& beamPath)
{
  beamPath.clear();
  int iterations = 0;
  beamPath.push_back(beam.p1());
  beamPath.push_back(beam.p2());
  while (iterations < 1000)
  {
    iterations++;
    qreal nearest_length = 1e9;
    QPolygonF polygon_reflections, nearest_polygon_reflections;
    QLineF original_beam = beam, nearest_beam;

    foreach(GameObject* game_object, objects_)
    {
      beam = original_beam;
      qreal distance = 0;
      if (game_object->ReflectBeam(beam, polygon_reflections, distance))
        if (distance < nearest_length)
        {
          nearest_length = distance;
          nearest_polygon_reflections = polygon_reflections;
          nearest_beam = beam;
        }
    }
    if (!(nearest_length < 1e9))
      break;

    beam = nearest_beam;
    beamPath << nearest_polygon_reflections;
  }
  beam.setLength(500);
  beamPath.push_back(beam.p2());
}
