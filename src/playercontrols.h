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
    Player* basePlayer = Player::findAppPlayer();
    QHBoxLayout* lay = nullptr;
public:
    PlayerControls();
    QPushButton* playButton = nullptr;
    QPushButton* pauseButton = nullptr;
};

#endif // PLAYERCONTROLS_H
