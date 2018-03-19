#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "infoswidget.h"
#include "videoplayerwidget.h"
#include <QMainWindow>


class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

public slots:
  //  InfosWidget getInfoWidget();
private:
    InfosWidget *infosWidget;
    VideoPlayerWidget *videoPlayerWidget;

};

#endif // MAINWINDOW_H
