#include "playerwindow.h"
#include "player.h"

#include <QAudioOutput>
#include <QDebug>
#include <QUrl>
#include <QString>
#include <QVariant>
#include <QGridLayout>
#include <QFileDialog>


PlayerWindow::PlayerWindow(QWidget *parent)
    : QWidget(parent)
{
    // initialize basePlayer pointer
    basePlayer = qApp->findChild<Player*>("player");

    auto* lay = new QGridLayout(this);

    this->fileDialogButton = new QToolButton;
    fileDialogButton->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
    connect(fileDialogButton, &QPushButton::pressed, this, &PlayerWindow::updatePlaylistFromFileDialog);
    lay->addWidget(fileDialogButton, 0,2);

    this->playButton = new QPushButton;
    playButton->setText("Play song");
    connect(playButton, SIGNAL(pressed()), basePlayer, SLOT(setSourceIfNoMedia()));
    connect(playButton, SIGNAL(pressed()), basePlayer, SLOT(play()));
    lay->addWidget(playButton, 0,0);

    this->pauseButton = new QPushButton;
    pauseButton->setText("Pause song");
    connect(pauseButton, SIGNAL(pressed()), basePlayer, SLOT(pause()));
    lay->addWidget(pauseButton, 0,1);

    this->playerStatusDisplay = new QLabel;
    playerStatusDisplay->setText("Media status: N/A");
    lay->addWidget(playerStatusDisplay, 2,0, 1,3, Qt::AlignCenter);
    updatePlayerStatusDisplay(basePlayer->mediaStatus());
    connect(basePlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(updatePlayerStatusDisplay(QMediaPlayer::MediaStatus)));

    setLayout(lay);
}

PlayerWindow::~PlayerWindow() {}

void PlayerWindow::updatePlaylistFromFileDialog()
{
    qDebug() << Q_FUNC_INFO;
    basePlayer->addToPlaylist(QFileDialog::getOpenFileName());
}

void PlayerWindow::updatePlayerStatusDisplay(QMediaPlayer::MediaStatus status)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << status;
    QString statusStr = QVariant::fromValue(status).toString();
    playerStatusDisplay->setText("Media status: " + statusStr);
}
