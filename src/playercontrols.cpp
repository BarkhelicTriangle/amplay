#include "playercontrols.h"

#include <QObject>
#include <QFileDialog>

PlayerControls::PlayerControls() : QWidget()
{
    basePlayer = Player::findAppPlayer();
    setWindowTitle("amplay PlayerControls");

    lay = new QHBoxLayout(this);

    this->playButton = new QPushButton(this);
    playButton->setText("Play");
    connect(playButton, SIGNAL(pressed()), basePlayer, SLOT(setSourceIfNoMedia()));
    connect(playButton, SIGNAL(pressed()), basePlayer, SLOT(play()));
    lay->addWidget(playButton, 0);

    this->pauseButton = new QPushButton(this);
    pauseButton->setText("Pause");
    connect(pauseButton, SIGNAL(pressed()), basePlayer, SLOT(pause()));
    lay->addWidget(pauseButton, 1);
}
