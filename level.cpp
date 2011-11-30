#include "level.h"
#include "graphwidget.h"

#include <iostream>

Level::Level()
{
  beam_item_ = 0;
}

void Level::SendBeam(QGraphicsScene& scene, const QLineF& beam)
{
  if (beam_item_)
    RemoveLastBeam(scene);
  std::cerr << "Adding beam" << std::endl;
  beam_item_ = scene.addLine(beam);
}

void Level::RemoveLastBeam(QGraphicsScene& scene)
{
  if (!beam_item_)
    return;
  std::cerr << "Removing beam" << std::endl;
  scene.removeItem(beam_item_);
  beam_item_ = 0;
}

