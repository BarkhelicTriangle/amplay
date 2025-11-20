#include "mainwindow.h"

#include <QAudioOutput>
#include <QDebug>
#include <QUrl>
#include <QString>
#include <QVariant>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // initialize the player first thing
    this->player = new QMediaPlayer();
    player->setAudioOutput(new QAudioOutput);
    connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(mediaStatusChanged(QMediaPlayer::MediaStatus)));

    auto* lay = new QGridLayout(this);

    this->filePathField = new QLineEdit;
    filePathField->setPlaceholderText("Enter a song's file path here");
    lay->addWidget(filePathField, 0, 0);

    this->loadButton = new QPushButton();
    loadButton->setText("Load song");
    connect(loadButton, SIGNAL(pressed()), this, SLOT(loadButtonPressed()));
    lay->addWidget(loadButton, 0, 1);

    this->playButton = new QPushButton();
    playButton->setText("Play song");
    connect(playButton, SIGNAL(pressed()), player, SLOT(play()));
    lay->addWidget(playButton, 1,0);

    this->pauseButton = new QPushButton();
    pauseButton->setText("Pause song");
    connect(pauseButton, SIGNAL(pressed()), player, SLOT(pause()));
    lay->addWidget(pauseButton, 1,1);

    this->playerStatusDisplay = new QLabel();
    playerStatusDisplay->setText("Media status: N/A");
    lay->addWidget(playerStatusDisplay, 2,0, 1,2, Qt::AlignCenter);

    this->setLayout(lay);
}

MainWindow::~MainWindow() {}

void MainWindow::loadButtonPressed()
{
    QUrl path = filePathField->text();
    player->setSource(path);
}

void MainWindow::mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    QString statusStr = QVariant::fromValue(status).toString();
    this->playerStatusDisplay->setText("Media status: " + statusStr);
}
