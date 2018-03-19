#include "videoplayerwidget.h"


VideoPlayerWidget::VideoPlayerWidget(QWidget *parent/*,InfosWidget *infosWidgetParallel*/) : QWidget(parent)
{

    player = new QMediaPlayer(this);

    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(durationChanged(qint64)));
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));

    mediaUrl = QUrl();

    videoTitleLabel = new QLabel();

    videoWidget = new VideoWidget(this);
    player->setVideoOutput(videoWidget);


    openButton = new QPushButton("Open", this);
    connect(openButton, SIGNAL(clicked()), this, SLOT(open()));

    playButton = new QToolButton(this);
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    pauseButton = new QToolButton(this);
    pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

    connect(playButton, SIGNAL(clicked()), player, SLOT(play()));
    connect(pauseButton, SIGNAL(clicked()), player, SLOT(pause()));

    durationSlider = new QSlider(Qt::Orientation::Horizontal, this);
    durationSlider->setRange(0, player->duration());

    connect(durationSlider, SIGNAL(sliderMoved(int)), this, SLOT(seek(int)));

    durationLabel = new QLabel("0:00/0:00", this);

    QBoxLayout *controlsLayout = new QHBoxLayout();
    controlsLayout->addWidget(openButton);
    controlsLayout->addWidget(playButton);
    controlsLayout->addWidget(pauseButton);
    controlsLayout->addWidget(durationSlider);
    controlsLayout->addWidget(durationLabel);

    QBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(videoTitleLabel);
    layout->addWidget(videoWidget, 2);
    layout->addLayout(controlsLayout);

    setLayout(layout);
}

void VideoPlayerWidget::open() {
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle("Open Video");
    QStringList supportedMimeTypes = player->supportedMimeTypes();
    if (!supportedMimeTypes.isEmpty()) {
        fileDialog.setMimeTypeFilters(supportedMimeTypes);
    }
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath()));
    if (fileDialog.exec() == QDialog::Accepted) {
        mediaUrl = fileDialog.selectedUrls().at(0);
        player->setMedia(mediaUrl);
        videoTitleLabel->setText(mediaUrl.toString());
        //the following line sends signal "videoOpened()" to infosWidget to launch InfosWidget::openAuto()
        emit videoOpened();

    }
}

void VideoPlayerWidget::durationChanged(qint64 duration) {
    this->duration = duration/1000;
    durationSlider->setMaximum(duration);
}

void VideoPlayerWidget::positionChanged(qint64 position) {
    durationSlider->setSliderPosition(position);
    updateDurationInfo(position/1000);
}

void VideoPlayerWidget::updateDurationInfo(qint64 currentInfo) {
    QString tStr;
    if (currentInfo || duration) {
        QTime currentTime((currentInfo/3600)%60, (currentInfo/60)%60, currentInfo%60, (currentInfo*1000)%1000);
        QTime totalTime((duration/3600)%60, (duration/60)%60, duration%60, (duration*1000)%1000);
        QString format = "mm:ss";
        if (duration > 3600) {
            format = "hh:mm:ss";
        }
        tStr = currentTime.toString(format) + "/" + totalTime.toString(format);
    }
    durationLabel->setText(tStr);
}

void VideoPlayerWidget::seek(int milliseconds) {
    player->setPosition(milliseconds);
}
