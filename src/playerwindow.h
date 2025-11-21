#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include "player.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>
#include <QQueue>

class PlayerWindow : public QWidget
{
    Q_OBJECT

public:
    PlayerWindow(QWidget *parent = nullptr);
    ~PlayerWindow();

private:
    Player* basePlayer;

    QPushButton* fileDialogButton = nullptr;
    QPushButton* playButton = nullptr;
    QPushButton* pauseButton = nullptr;

    QLabel* playerStatusDisplay = nullptr;

private slots:
    void updatePlaylistFromFileDialog();
    void updatePlayerStatusDisplay();
};
#endif // PLAYERWINDOW_H
