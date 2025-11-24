#include "playercontrols.h"

#include <QObject>
#include <QFileDialog>

PlayerControls::PlayerControls() : QWidget()
{
    basePlayer = qApp->findChild<Player*>("player");

    lay = new QHBoxLayout(this);

    this->playButton = new QPushButton;
    playButton->setText("Play");
    connect(playButton, SIGNAL(pressed()), basePlayer, SLOT(setSourceIfNoMedia()));
    connect(playButton, SIGNAL(pressed()), basePlayer, SLOT(play()));
    lay->addWidget(playButton, 0);

    this->pauseButton = new QPushButton;
    pauseButton->setText("Pause");
    connect(pauseButton, SIGNAL(pressed()), basePlayer, SLOT(pause()));
    lay->addWidget(pauseButton, 1);

    this->playlistAddButton = new QPushButton;
    playlistAddButton->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
    connect(playlistAddButton, &QPushButton::pressed, this, &PlayerControls::updatePlaylistFromFileDialog);
    lay->addWidget(playlistAddButton, 2);
}

void PlayerControls::updatePlaylistFromFileDialog()
{
    basePlayer->addToPlaylist(QFileDialog::getOpenFileUrl());
    qDebug() << basePlayer->playlist;
}
