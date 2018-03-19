#include "infoswidget.h"

InfosWidget::InfosWidget(QWidget *parent, QWidget *player) : QWidget(parent)
{

    algoWidget = new AlgorithmWidget(this);


    QLabel *titleLabel = new QLabel("micro-expressions list", this);

    meList = new QVector<QStringList>();


    QPushButton *goToTimestamp = new QPushButton("Go to selected timestamp");
    connect(goToTimestamp, SIGNAL(clicked(bool)), this, SLOT(goToTS()));

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(3);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setSelectionBehavior( QAbstractItemView::SelectItems );
    tableWidget->setSelectionMode( QAbstractItemView::SingleSelection );

    addButton = new QPushButton("Add", this);
    connect(addButton, SIGNAL(clicked(bool)), this, SLOT(addME()));

    deleteButton = new QPushButton("Delete", this);
    connect(deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteME()));

    saveButton = new QPushButton("Save", this);
    connect(saveButton, SIGNAL(clicked(bool)), this, SLOT(save()));

    openButton = new QPushButton("Open", this);
    connect(openButton, SIGNAL(clicked()), this, SLOT(open()));

    connect(player, SIGNAL(videoOpened()), this, SLOT(openAuto()));

    QBoxLayout *layout = new QVBoxLayout();
    QBoxLayout *topLayout = new QHBoxLayout();
    QBoxLayout *buttonLayout = new QHBoxLayout();

    topLayout->addWidget(titleLabel);
    topLayout->addWidget(goToTimestamp);


    buttonLayout->addWidget(openButton);
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(saveButton);

    layout->addWidget(algoWidget);
    layout->addLayout(topLayout);
    layout->addWidget(tableWidget);

    layout->addLayout(buttonLayout);

    setLayout(layout);

}

void InfosWidget::open() {
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle("Open timestamps file");
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).value(0, QDir::homePath()));

    if (fileDialog.exec() == QDialog::Accepted) {
        timestampsFile = new QFile(fileDialog.selectedFiles().at(0));
        if (timestampsFile->open(QIODevice::ReadOnly))
        {
           clearTable();
           meList = new QVector<QStringList>();
           QTextStream in(timestampsFile);
           while (!in.atEnd())
           {
              QString line = in.readLine();
              QStringList *nextData = new QStringList(line.split(QChar(';')));
              meList->append(*nextData);
           }

           timestampsFile->close();
        }
        updateTable();
    }
}
//open automatically file if exists when opening a video
void InfosWidget::openAuto() {
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle("Open timestamps file");
   // fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).value(0, QDir::homePath()));

    if (fileDialog.exec() == QDialog::Accepted) {
        timestampsFile = new QFile(fileDialog.selectedFiles().at(0));
        if (timestampsFile->open(QIODevice::ReadOnly))
        {
           clearTable();
           meList = new QVector<QStringList>();
           QTextStream in(timestampsFile);
           while (!in.atEnd())
           {
              QString line = in.readLine();
              QStringList *nextData = new QStringList(line.split(QChar(';')));
              meList->append(*nextData);
           }

           timestampsFile->close();
        }
        updateTable();
    }
}

void InfosWidget::clearTable() {
    for (int r=0; r<tableWidget->rowCount(); ++r) {
        tableWidget->removeRow(r);
    }
}

void InfosWidget::updateTable() {
    clearTable();
    tableWidget->setRowCount(0);
    for (int r=0; r<meList->count(); ++r) {
        tableWidget->insertRow(r);
        for (int c=0; c<3; ++c) {
            tableWidget->setItem(r, c, new QTableWidgetItem(meList->at(r).at(c)));
            if(c<2) {

            }
        }
    }
}

void InfosWidget::addME() {
    bool ok = false;
    QString onset(""), offset(""), emotion("");
    while (!ok) {
        onset = QInputDialog::getText(this, "Add a timestamp", "Onset (frame) = ", QLineEdit::Normal, "", &ok);
    }
    ok = false;
    while (!ok) {
        offset = QInputDialog::getText(this, "Add a timestamp", "Offset (frame) = ", QLineEdit::Normal, "", &ok);
    }
    ok = false;
    while (!ok) {
        emotion = QInputDialog::getText(this, "Add a timestamp", "Emotion = ", QLineEdit::Normal, "", &ok);
    }




    QStringList *newSL = new QStringList();
    newSL->append(onset);
    newSL->append(offset);
    newSL->append(emotion);
    meList->append(*newSL);
    updateTable();
}

void InfosWidget::deleteME() {
    if (!tableWidget->selectedItems().isEmpty()) {
        int row = tableWidget->selectedItems().at(0)->row();
        meList->remove(row);
        updateTable();
    }
}
void InfosWidget::save() {
    QString filename = QFileDialog::getSaveFileName(this, "Save File", "", tr("*.txt"));
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        for (int i=0; i<meList->count(); ++i) {
            stream << meList->at(i).at(0) << ";" << meList->at(i).at(1) << ";" << meList->at(i).at(2) << '\n';
        }
        file.close();
    }
}

void InfosWidget::goToTS() {
    if (!tableWidget->selectedItems().isEmpty()) {
        QString value = tableWidget->selectedItems().at(0)->text();
        bool ok;
        int intOfValue = value.toInt(&ok);
        if (ok) {
            //communiquer avec video player widget pour changer la position
        }
    }
}
