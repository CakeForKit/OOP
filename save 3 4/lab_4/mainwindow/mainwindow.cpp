#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) 
{
    this->setWindowTitle("Lift");
    widget = lift.getWidgetController();
    widget->setParent(this);
    setCentralWidget(widget);
}