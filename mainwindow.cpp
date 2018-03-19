#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Lie to Me - App");

    videoPlayerWidget = new VideoPlayerWidget(this);
    infosWidget = new InfosWidget(this,videoPlayerWidget);


    QBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(videoPlayerWidget, 2);
    layout->addWidget(infosWidget);

    setLayout(layout);
}

