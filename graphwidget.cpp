#include "graphwidget.h"

#include <QtGui>

#include <iostream>

Level create_test_level()
{
  Level test_level;
  test_level.name_ = "Test_Level";
  GameObject* reflector = new GameObject();
  reflector->center_ = QPointF(1.0, 1.0);
  reflector->body_.push_back(QPointF(5, 3));
  reflector->body_.push_back(QPointF(1, 4));
  reflector->body_.push_back(QPointF(9, 2));
  reflector->body_.push_back(QPointF(5, 3));

  GameObject* absorber = new GameObject();
  absorber->center_ = QPointF(3.0, -1.0);
  absorber->body_.push_back(QPointF(0, 44));
  absorber->body_.push_back(QPointF(3, 13));
  absorber->body_.push_back(QPointF(5, 23));

  test_level.objects_.push_back(reflector);
  test_level.objects_.push_back(absorber);

  return test_level;
}

GraphWidget::GraphWidget(QWidget *parent) :
    QGraphicsView(parent)
{
  level_manager_ = new LevelManager();

  Level test_level = create_test_level();
  level_manager_->WriteLevel("test_level.xml", test_level);

  Level read_level;
  int result = level_manager_->ReadLevel("test_level.xml", read_level);
  std::cerr << result << std::endl;
  std::cerr << read_level.name_.toStdString() << std::endl;
  std::cerr << read_level.objects_.size() << std::endl;
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
