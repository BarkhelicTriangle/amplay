#include "mainwindow.h"

#include <QAudioOutput>
#include <QDebug>
#include <QUrl>
#include <QString>
#include <QVariant>
#include <QGridLayout>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // initialize the player first thing
    this->player = new QMediaPlayer();
    player->setAudioOutput(new QAudioOutput);
    connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(updatePlayerStatusDisplay(QMediaPlayer::MediaStatus)));

    auto* lay = new QGridLayout(this);

    this->filePathField = new QLineEdit;
    filePathField->setPlaceholderText("Enter a song's file path here");
    lay->addWidget(filePathField, 0,0);

    this->loadButton = new QPushButton;
    loadButton->setText("Load song");
    connect(loadButton, SIGNAL(pressed()), this, SLOT(updatePlayerSource()));
    lay->addWidget(loadButton, 0,1);

    this->fileDialogButton = new QToolButton;
    fileDialogButton->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
    connect(fileDialogButton, SIGNAL(pressed()), this, SLOT(presentPlayerSourceFileDialog()));
    lay->addWidget(fileDialogButton, 0,2);

    this->playButton = new QPushButton;
    playButton->setText("Play song");
    connect(playButton, SIGNAL(pressed()), player, SLOT(play()));
    lay->addWidget(playButton, 1,1);

    this->pauseButton = new QPushButton;
    pauseButton->setText("Pause song");
    connect(pauseButton, SIGNAL(pressed()), player, SLOT(pause()));
    lay->addWidget(pauseButton, 1,0);

    this->playerStatusDisplay = new QLabel;
    playerStatusDisplay->setText("Media status: N/A");
    lay->addWidget(playerStatusDisplay, 2,0, 1,3, Qt::AlignCenter);
    updatePlayerStatusDisplay(player->mediaStatus());

    setLayout(lay);
}

MainWindow::~MainWindow() {}

void MainWindow::positionChanged(qint64 pos)
{
    qDebug() << pos;
}

void MainWindow::presentPlayerSourceFileDialog()
{
    filePathField->setText(QFileDialog::getOpenFileName());
}

void MainWindow::updatePlayerSource()
{
    QUrl path = filePathField->text();
    this->playlist.enqueue(path);
    if (player->mediaStatus() == QMediaPlayer::NoMedia) player->setSource(path);
    qDebug() << playlist;
}

void MainWindow::updatePlayerStatusDisplay(QMediaPlayer::MediaStatus status)
{
    qDebug() << status;
    QString statusStr = QVariant::fromValue(status).toString();
    playerStatusDisplay->setText("Media status: " + statusStr);
    if (status == QMediaPlayer::EndOfMedia)
    {
        playlist.dequeue();
        player->setSource(playlist.head());
    }
}
