#include "mainwindow.h"

#include <QAudioOutput>
#include <QDebug>
#include <QUrl>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->player = new QMediaPlayer();
    player->setAudioOutput(new QAudioOutput);
    connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(mediaStatusChanged(QMediaPlayer::MediaStatus)));

    QVBoxLayout* lay = new QVBoxLayout(this);

    this->filepath_field = new QLineEdit;
    filepath_field->setPlaceholderText("Enter a song's file path here");
    lay->addWidget(filepath_field);

    this->load_button = new QPushButton();
    load_button->setText("Load song");
    connect(load_button, SIGNAL(pressed()), this, SLOT(loadButtonPressed()));
    lay->addWidget(load_button);

    this->play_button = new QPushButton();
    play_button->setText("Play song");
    connect(play_button, SIGNAL(pressed()), player, SLOT(play()));
    lay->addWidget(play_button);

    this->pause_button = new QPushButton();
    pause_button->setText("Pause song");
    connect(pause_button, SIGNAL(pressed()), player, SLOT(pause()));
    lay->addWidget(pause_button);

    this->setLayout(lay);

}

MainWindow::~MainWindow() {}

void MainWindow::loadButtonPressed()
{
    this->player->setSource(QUrl(this->filepath_field->text()));
}

void MainWindow::mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    qInfo() << status;
}
