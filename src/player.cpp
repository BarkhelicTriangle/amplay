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
    qDebug() << Q_FUNC_INFO;
    if (path == QUrl("")) return;

    this->playlist.enqueue(path);
    qDebug() << playlist;
}

void Player::removeSongAfterFinish(QMediaPlayer::MediaStatus status)
{
    qDebug() << Q_FUNC_INFO;
    if (status != QMediaPlayer::EndOfMedia) return;

    playlist.dequeue();
    setSource(playlist.head());
}

void Player::setSourceIfNoMedia()
{
    qDebug() << Q_FUNC_INFO;

    // calling head on empty QQueue crashes || no reason to keep going if no Media
    if (playlist.isEmpty() || mediaStatus() != NoMedia) return;

    setSource(playlist.head());
}
