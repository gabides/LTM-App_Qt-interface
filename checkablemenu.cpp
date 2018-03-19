#include "checkablemenu.h"

CheckableMenu::CheckableMenu(QWidget *parent)
        : QWidget(parent), isChecked(false), animation(this, "size")
{
    animation.setDuration(1000);

    layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setLayout(layout);

}

void CheckableMenu::addWidget(QWidget *widget) {
    layout->addWidget(widget);
}


void CheckableMenu::checked() {
    if (isChecked) {
        animation.setStartValue(QSize(width(), 0));
        animation.setEndValue(lastSize);
        animation.start();
        isChecked = false;
    } else {
        lastSize = size();
        animation.setStartValue(lastSize);
        animation.setEndValue(QSize(width(), 0));
        animation.start();
        isChecked = true;
    }
}
