#ifndef PLAYERCONTROLS_H
#define PLAYERCONTROLS_H

#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QHBoxLayout>

#include "player.h"

class PlayerControls : public QWidget
{
    Q_OBJECT
private:
    Player* basePlayer;
    QHBoxLayout* lay = nullptr;
public:
    PlayerControls();
    QPushButton* playlistAddButton = nullptr;
    QPushButton* playButton = nullptr;
    QPushButton* pauseButton = nullptr;

private slots:
    void updatePlaylistFromFileDialog();
};

#endif // PLAYERCONTROLS_H
