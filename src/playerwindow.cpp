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

    this->filePathField = new QLineEdit;
    filePathField->setPlaceholderText("Enter a song's file path here");
    lay->addWidget(filePathField, 0,0);

    this->loadButton = new QPushButton;
    loadButton->setText("Load song");
    connect(loadButton, &QPushButton::pressed,
            this, [=] {
                basePlayer->addToPlaylist(QUrl(filePathField->text()));
            }
    );
    connect(loadButton, &QPushButton::pressed, basePlayer, &Player::setSourceIfNoMedia);
    lay->addWidget(loadButton, 0,1);

    this->fileDialogButton = new QToolButton;
    fileDialogButton->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
    connect(fileDialogButton, &QPushButton::pressed, this, &PlayerWindow::updatePathFieldFromFileDialog);
    lay->addWidget(fileDialogButton, 0,2);

    this->playButton = new QPushButton;
    playButton->setText("Play song");
    connect(playButton, SIGNAL(pressed()), basePlayer, SLOT(play()));
    lay->addWidget(playButton, 1,1);

    this->pauseButton = new QPushButton;
    pauseButton->setText("Pause song");
    connect(pauseButton, SIGNAL(pressed()), basePlayer, SLOT(pause()));
    lay->addWidget(pauseButton, 1,0);

    this->playerStatusDisplay = new QLabel;
    playerStatusDisplay->setText("Media status: N/A");
    lay->addWidget(playerStatusDisplay, 2,0, 1,3, Qt::AlignCenter);
    updatePlayerStatusDisplay(basePlayer->mediaStatus());
    connect(basePlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(updatePlayerStatusDisplay(QMediaPlayer::MediaStatus)));

    setLayout(lay);
}

PlayerWindow::~PlayerWindow() {}

void PlayerWindow::updatePathFieldFromFileDialog()
{
    filePathField->setText(QFileDialog::getOpenFileName());
}

void PlayerWindow::updatePlayerStatusDisplay(QMediaPlayer::MediaStatus status)
{
    qDebug() << status;
    QString statusStr = QVariant::fromValue(status).toString();
    playerStatusDisplay->setText("Media status: " + statusStr);
}
