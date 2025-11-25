#include "player.h"

#include <QAudioOutput>
#include <QDebug>

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
    qDebug() << Q_FUNC_INFO;
    return qApp->findChild<Player*>("player");
}


void Player::addToQueue(QUrl path)
{
    qDebug() << Q_FUNC_INFO;

    // this will be true if the user cancels
    if (path == QUrl("")) return;

    this->queue.enqueue(path);
    emit playlistChanged();
}

void Player::removeSongAfterFinish(QMediaPlayer::MediaStatus status)
{
    qDebug() << Q_FUNC_INFO;
    if (status != QMediaPlayer::EndOfMedia) return;

    queue.dequeue();
    if(queue.isEmpty()) return;

    //this should be moved elsewhere
    setSource(queue.head());

    emit playlistChanged();
}

void Player::setSourceIfNoMedia()
{
    qDebug() << Q_FUNC_INFO;

    // calling head on empty QQueue crashes || no reason to keep going if no Media
    if (queue.isEmpty() || mediaStatus() != NoMedia) return;
    setSource(queue.head());
}

void Player::playSongWhenLoaded(QMediaPlayer::MediaStatus status)
{
    qDebug() << Q_FUNC_INFO;

    if (status != LoadedMedia) return;
    emit play();
}
