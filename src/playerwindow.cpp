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

    this->playButton = new QPushButton;
    playButton->setText("Play");
    connect(playButton, SIGNAL(pressed()), basePlayer, SLOT(setSourceIfNoMedia()));
    connect(playButton, SIGNAL(pressed()), basePlayer, SLOT(play()));
    lay->addWidget(playButton, 0,0);

    this->pauseButton = new QPushButton;
    pauseButton->setText("Pause");
    connect(pauseButton, SIGNAL(pressed()), basePlayer, SLOT(pause()));
    lay->addWidget(pauseButton, 0,1);

    this->fileDialogButton = new QPushButton;
    fileDialogButton->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
    connect(fileDialogButton, &QPushButton::pressed, this, &PlayerWindow::updatePlaylistFromFileDialog);
    lay->addWidget(fileDialogButton, 0,2);

    this->playerStatusDisplay = new QLabel;
    playerStatusDisplay->setText("Media status: N/A");
    lay->addWidget(playerStatusDisplay, 2,0, 1,3, Qt::AlignCenter);
    updatePlayerStatusDisplay();
    connect(basePlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(updatePlayerStatusDisplay()));

    setLayout(lay);
}

PlayerWindow::~PlayerWindow() {}

void PlayerWindow::updatePlaylistFromFileDialog()
{
    qDebug() << Q_FUNC_INFO;
    basePlayer->addToPlaylist(QFileDialog::getOpenFileName());
    basePlayer->setSourceIfNoMedia();
}

void PlayerWindow::updatePlayerStatusDisplay()
{
    qDebug() << Q_FUNC_INFO;

    // there should be a method of Player that returns all of this as a struct or something
    QTextStream statusStream;
    statusStream.setString(new QString);

    statusStream << "basePlayer status: " << QVariant::fromValue(basePlayer->mediaStatus()).toString() << '\n';
    statusStream << "Current file: " << basePlayer->source().fileName();
    playerStatusDisplay->setText(statusStream.readAll());
}
