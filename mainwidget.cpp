#include "mainwidget.h"
#include "graphwidget.h"

#include <QtGui>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();
    QPushButton *start_button = new QPushButton("start");
    QPushButton *options_button = new QPushButton("options");
    QPushButton *exit_button = new QPushButton("exit");

    layout->addWidget(start_button);
    layout->addWidget(options_button);
    layout->addWidget(exit_button);

    connect(start_button, SIGNAL(clicked()), this, SLOT(StartGame()));
    connect(exit_button, SIGNAL(clicked()), qApp, SLOT(quit()));

    this->setLayout(layout);
}

void MainWidget::StartGame()
{
  GraphWidget *game_widget = new GraphWidget();
  this->hide();
  game_widget->show();
}
