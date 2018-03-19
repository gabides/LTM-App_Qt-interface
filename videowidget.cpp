#include "videowidget.h"


VideoWidget::VideoWidget(QWidget *parent)
    : QVideoWidget(parent)
{
    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::black);
    setPalette(p);

    setAttribute(Qt::WA_OpaquePaintEvent);
}
