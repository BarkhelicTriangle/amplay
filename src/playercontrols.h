#pragma once

#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>

#include "player.h"

class PlayerControls : public QWidget
{
    Q_OBJECT
private:
    Player* basePlayer = nullptr;
    QHBoxLayout* lay = nullptr;
public:
    PlayerControls();
    QPushButton* playButton = nullptr;
    QPushButton* pauseButton = nullptr;
};
