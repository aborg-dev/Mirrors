#include "graphwidget.h"

#include <QtGui>

GraphWidget::GraphWidget(QWidget *parent) :
    QGraphicsView(parent)
{

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
