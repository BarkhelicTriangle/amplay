#include "mainwindow.h"

#include <QAudioOutput>
#include <QDebug>
#include <QUrl>
#include <QString>
#include <QVariant>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // initialize the player first thing
    this->player = new QMediaPlayer();
    player->setAudioOutput(new QAudioOutput);
    connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(mediaStatusChanged(QMediaPlayer::MediaStatus)));

    // will definitely have to switch to QGridLayout sooner than later
    QVBoxLayout* lay = new QVBoxLayout(this);

    this->filePathField = new QLineEdit;
    filePathField->setPlaceholderText("Enter a song's file path here");
    lay->addWidget(filePathField);

    this->loadButton = new QPushButton();
    loadButton->setText("Load song");
    connect(loadButton, SIGNAL(pressed()), this, SLOT(loadButtonPressed()));
    lay->addWidget(loadButton);

    this->playButton = new QPushButton();
    playButton->setText("Play song");
    connect(playButton, SIGNAL(pressed()), player, SLOT(play()));
    lay->addWidget(playButton);

    this->pauseButton = new QPushButton();
    pauseButton->setText("Pause song");
    connect(pauseButton, SIGNAL(pressed()), player, SLOT(pause()));
    lay->addWidget(pauseButton);

    this->playerStatus = new QLabel();
    lay->addWidget(playerStatus);

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
    this->playerStatus->setText(statusStr);
}
