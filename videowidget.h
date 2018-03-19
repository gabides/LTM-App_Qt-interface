#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QVideoWidget>
#include <QPalette>


class VideoWidget : public QVideoWidget
{
    Q_OBJECT

public:
    VideoWidget(QWidget *parent = nullptr);
};

#endif // VIDEOWIDGET_H
