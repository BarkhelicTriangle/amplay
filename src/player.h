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
    // if i'm being honest a QList would probably be better, would absolutely be easier to use
    QQueue<QUrl> playlist;
    explicit Player(QApplication *parent = nullptr);

public slots:
    void updatePlayerSource(QUrl path);

signals:
};

#endif // PLAYER_H
