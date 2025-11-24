#include "playerwindow.h"
#include "player.h"

#include <QAudioOutput>
#include <QDebug>
#include <QUrl>
#include <QString>
#include <QVariant>
#include <QGridLayout>
#include <QFileDialog>
#include <QMediaMetadata>


PlayerWindow::PlayerWindow(QWidget *parent)
    : QWidget(parent)
{
    // initialize basePlayer pointer
    basePlayer = qApp->findChild<Player*>("player");

    auto* lay = new QGridLayout(this);

    this->metadataTextDisplay = new QLabel;
    metadataTextDisplay->setText("Media status: N/A");
    lay->addWidget(metadataTextDisplay, 2,0, 1,3, Qt::AlignLeft);
    //updatePlayerStatusDisplay();
    connect(basePlayer, &Player::mediaStatusChanged, this, &PlayerWindow::updateMetadataTextDisplay);

    setLayout(lay);
}

PlayerWindow::~PlayerWindow() {}

void PlayerWindow::updatePlaylistFromFileDialog()
{
    qDebug() << Q_FUNC_INFO;
    basePlayer->addToPlaylist(QFileDialog::getOpenFileName());
    basePlayer->setSourceIfNoMedia();
}

void PlayerWindow::updateMetadataTextDisplay(QMediaPlayer::MediaStatus status)
{
    qDebug() << Q_FUNC_INFO;

    if (status != QMediaPlayer::LoadedMedia) return;

    QTextStream statusStream;
    statusStream.setString(new QString);

    QString songArtist = basePlayer->metaData().stringValue(QMediaMetaData::ContributingArtist);
    QString songTitle = basePlayer->metaData().stringValue(QMediaMetaData::Title);

    qDebug() << basePlayer->metaData();

    statusStream << "Now playing: " << songArtist << " - " << songTitle;
    metadataTextDisplay->setText(statusStream.readAll());
}
