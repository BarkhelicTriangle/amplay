#pragma once

#include <QApplication>
#include <QMediaPlayer>
#include <QQueue>
#include <QUrl>
#include <QAudioBuffer>

struct QueueItem {
    QUrl filePath;
    QAudioBuffer* buffer;

    QueueItem(QUrl pFilePath, QAudioBuffer* pBuffer) {
        filePath = pFilePath;
        buffer = pBuffer;
    }
};

class Player : public QMediaPlayer
{
    Q_OBJECT
public:
    QQueue<QueueItem> queue;
    explicit Player(QApplication *parent = nullptr);
    static Player* findAppPlayer();

public slots:
    void addToQueue(QUrl path);
    void setSourceIfNoMedia();
    void playSongWhenLoaded(QMediaPlayer::MediaStatus status);
    void removeSongAfterFinish(QMediaPlayer::MediaStatus status);

signals:
    void playlistChanged();
};
