#include "player.h"

#include <QAudioOutput>

Player::Player(QApplication *parent)
    : QMediaPlayer{parent}
{
    setObjectName("player");
    setAudioOutput(new QAudioOutput);
    connect(this, &Player::mediaStatusChanged, this, &Player::removeSongAfterFinish);
    connect(this, &Player::mediaStatusChanged, this, &Player::playSongWhenLoaded);
}

Player* Player::findAppPlayer()
{
    return qApp->findChild<Player*>("player");
}


void Player::addToPlaylist(QUrl path)
{
    qDebug() << Q_FUNC_INFO;
    if (path == QUrl("")) return;

    this->playlist.enqueue(path);
    qDebug() << playlist;

    emit playlistChanged();
}

void Player::removeSongAfterFinish(QMediaPlayer::MediaStatus status)
{
    qDebug() << Q_FUNC_INFO;
    if (status != QMediaPlayer::EndOfMedia) return;

    playlist.dequeue();

    if(playlist.isEmpty()) return;
    setSource(playlist.head());

    emit playlistChanged();
}

void Player::setSourceIfNoMedia()
{
    qDebug() << Q_FUNC_INFO;

    // calling head on empty QQueue crashes || no reason to keep going if no Media
    if (playlist.isEmpty() || mediaStatus() != NoMedia) return;

    setSource(playlist.head());
}

void Player::playSongWhenLoaded(QMediaPlayer::MediaStatus status)
{
    qDebug() << Q_FUNC_INFO;
    if (status != LoadedMedia) return;
    
    emit play();
}
