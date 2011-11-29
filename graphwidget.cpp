#include "graphwidget.h"

#include <QtGui>

GraphWidget::GraphWidget(QWidget *parent) :
    QGraphicsView(parent)
{
  level_manager_ = new LevelManager();
  Level test_level;
  test_level.name_ = "Test Level";
  GameObject reflector;
  reflector.center_ = QPointF(1.0, 1.0);
  reflector.body_.push_back(QPointF(5, 3));
  reflector.body_.push_back(QPointF(1, 4));
  reflector.body_.push_back(QPointF(9, 2));
  reflector.body_.push_back(QPointF(5, 3));

  GameObject absorber;
  absorber.center_ = QPointF(3.0, -1.0);
  absorber.body_.push_back(QPointF(0, 44));
  absorber.body_.push_back(QPointF(3, 13));
  absorber.body_.push_back(QPointF(5, 23));

  test_level.objects_.push_back(reflector);
  test_level.objects_.push_back(absorber);

  level_manager_->WriteLevel("test_level", test_level);
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
