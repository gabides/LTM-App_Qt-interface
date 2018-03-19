#ifndef CHECKABLEMENU_H
#define CHECKABLEMENU_H

//#include <QtGui/QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QObject>
#include <QWidget>
#include <QtGui>

#include <QPropertyAnimation>

class CheckableMenu : public QWidget
{
    Q_OBJECT
public:
    CheckableMenu(QWidget *parent = 0);
    void addWidget(QWidget *widget);

public slots:
    void checked();

private:
    QVBoxLayout* layout;
    bool isChecked;
    QSize lastSize;
    QPropertyAnimation animation;
};

#endif // CHECKABLEMENU_H
