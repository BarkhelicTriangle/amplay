#include "playercontrols.h"

#include <QObject>
#include <QFileDialog>

PlayerControls::PlayerControls() : QWidget()
{
    setWindowTitle("amplay PlayerControls");

    lay = new QHBoxLayout(this);

    // todo: see how clean this is? apply this style in queuewindow.cpp!!!
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
