#ifndef PLAYER_H
#define PLAYER_H

#include <QApplication>
#include <QDebug>
#include <QMediaPlayer>
#include <QQueue>
#include <QUrl>

class Player : public QMediaPlayer
{
    Q_OBJECT
public:
    QQueue<QUrl> queue;
    explicit Player(QApplication *parent = nullptr);
    static Player* findAppPlayer();

public slots:
    void addToPlaylist(QUrl path);
    void setSourceIfNoMedia();
    void playSongWhenLoaded(QMediaPlayer::MediaStatus status);
    void removeSongAfterFinish(QMediaPlayer::MediaStatus status);

signals:
    void playlistChanged();
};

#endif // PLAYER_H
