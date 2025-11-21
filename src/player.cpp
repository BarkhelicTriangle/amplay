#include "player.h"

#include <QAudioOutput>

Player::Player(QApplication *parent)
    : QMediaPlayer{parent}
{
    setAudioOutput(new QAudioOutput);
}


void Player::updatePlayerSource(QUrl path)
{
    this->playlist.enqueue(path);
    if (mediaStatus() == QMediaPlayer::NoMedia) setSource(path);
    qDebug() << playlist;
}
