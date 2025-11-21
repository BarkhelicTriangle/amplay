#include "player.h"

#include <QAudioOutput>

Player::Player(QApplication *parent)
    : QMediaPlayer{parent}
{
    setAudioOutput(new QAudioOutput);
    connect(this, &Player::mediaStatusChanged, this, &Player::removeSongAfterFinish);
}


void Player::addToPlaylist(QUrl path)
{
    if (path == QUrl("")) return;

    this->playlist.enqueue(path);
    qDebug() << playlist;
}

void Player::removeSongAfterFinish(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia)
    {
        playlist.dequeue();
        setSource(playlist.head());
    }
}

void Player::setSourceIfNoMedia()
{
    if (mediaStatus() == QMediaPlayer::NoMedia) setSource(playlist.head());
}
