#ifndef INFOSWIDGET_H
#define INFOSWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QAbstractButton>
#include <QFile>

#include "videoplayerwidget.h"
#include "algorithmwidget.h"

#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextStream>
#include <QInputDialog>
#include <QPropertyAnimation>


#include <iostream>


class InfosWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InfosWidget(QWidget *parent = nullptr,QWidget *player = nullptr);

signals:

public slots:
    void open();
    void openAuto();

    void addME();
    void deleteME();
    void save();
    void goToTS();

public:
    void clearTable();
    void updateTable();

private:
    AlgorithmWidget *algoWidget;

    QTableWidget *tableWidget;
    QAbstractButton *goToTimestamp;
    QAbstractButton *openButton;
    QAbstractButton *addButton;
    QAbstractButton *deleteButton;
    QAbstractButton *saveButton;

    QFile *timestampsFile;
    QVector<QStringList> *meList;

};

#endif // INFOSWIDGET_H
