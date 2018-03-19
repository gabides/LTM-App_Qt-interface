#include "algorithmwidget.h"

AlgorithmWidget::AlgorithmWidget(QWidget *parent) : QWidget(parent)
{

    QWidget* w = new QWidget;
    QBoxLayout* layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    w->setLayout(layout);
    //setCentralWidget(w);

    QPushButton* item1 = new QPushButton("Detection Algorithm selection :");
    layout->addWidget(item1);

    CheckableMenu* submenu1 = new CheckableMenu();
    layout->addWidget(submenu1);
    connect(item1, SIGNAL(clicked()), submenu1, SLOT(checked()));

    QPushButton* subitem1 = new QPushButton("Algorithm 1");
    submenu1->addWidget(subitem1);
    QPushButton* subitem2 = new QPushButton("Algorithm 2");
    submenu1->addWidget(subitem2);
    QPushButton* subitem3 = new QPushButton("Algorithm 3");
    submenu1->addWidget(subitem3);


/*
    QPushButton* item2 = new QPushButton("item 2");
    layout->addWidget(item2);

    QPushButton* item3 = new QPushButton("item 3");
    layout->addWidget(item3);
*/
   // layout->addStretch(1);

    setLayout(layout);
//    layout->setSizeConstraint(QLayout::SetMinimumSize);

}
