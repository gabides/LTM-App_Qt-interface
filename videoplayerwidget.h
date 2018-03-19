#ifndef VIDEOPLAYERWIDGET_H
#define VIDEOPLAYERWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAbstractButton>
#include <QSlider>
#include <QLabel>

#include <QToolButton>
#include <QStyle>
#include <QBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTime>

#include <iostream>

#include "videowidget.h"
#include "infoswidget.h"

class VideoPlayerWidget : public QWidget //, InfosWidget
{
    Q_OBJECT
public:
    explicit VideoPlayerWidget(QWidget *parent = nullptr);

    void updateDurationInfo(qint64 position);

signals:
    void videoOpened();
public slots:
    void open();

    void seek(int milliseconds);

    void durationChanged(qint64 duration);
    void positionChanged(qint64 currentInfo);

private:
    QMediaPlayer *player;
    QUrl mediaUrl;
    QLabel *videoTitleLabel;
    VideoWidget *videoWidget;
    QAbstractButton *openButton;
    QAbstractButton *playButton;
    QAbstractButton *pauseButton;
    QSlider *durationSlider;
    QLabel *durationLabel;
    qint64 duration;


};

#endif // VIDEOPLAYERWIDGET_H
