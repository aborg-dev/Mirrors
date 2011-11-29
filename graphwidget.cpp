#include "graphwidget.h"

#include <QtGui>

#include <iostream>

GraphWidget::GraphWidget(QWidget *parent) :
    QGraphicsView(parent)
{
  level_manager_ = new LevelManager();

  Level test_level = level_manager_->create_test_level();

  level_manager_->WriteLevel("test_level.xml", test_level);

  QGraphicsScene *scene = new QGraphicsScene(this);
  scene->setItemIndexMethod(QGraphicsScene::NoIndex);
  scene->setSceneRect(-200, -200, 400, 400);
  setScene(scene);
  setCacheMode(CacheBackground);
  setViewportUpdateMode(BoundingRectViewportUpdate);
  setRenderHint(QPainter::Antialiasing);
  setTransformationAnchor(AnchorUnderMouse);
  scale(qreal(0.8), qreal(0.8));
  setMinimumSize(400, 400);
  setWindowTitle(tr("Mirrors"));

  LoadMainLevel(test_level);
  /*Level read_level;
  int result = level_manager_->ReadLevel("test_level.xml", read_level);
  std::cerr << result << std::endl;
  std::cerr << read_level.name_.toStdString() << std::endl;
  std::cerr << read_level.objects_.size() << std::endl;*/
}

void GraphWidget::LoadMainLevel(const Level &main_level)
{
  main_level_ = new Level(main_level);
  foreach(GameObject* game_object, main_level_->objects_)
    game_object->SetGraphWidget(this);
}

void GraphWidget::keyPressEvent(QKeyEvent *event)
{
  switch (event->key()) {
  case Qt::Key_Escape:
    //call main menu, pause
    break;
  default:
    QGraphicsView::keyPressEvent(event);
  }
}
