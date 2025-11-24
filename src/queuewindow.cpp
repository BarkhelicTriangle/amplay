#include "queuewindow.h"
#include "player.h"
#include <QListWidget>
#include <QFileDialog>

QueueWindow::QueueWindow() : QWidget()
{
    setWindowTitle("amplay QueueDisplay");
    queueWidget->setViewMode(QListView::ListMode);
    connect(Player::findAppPlayer(), SIGNAL(playlistChanged()),
            this, SLOT(updateQueueDisplay()));

    lay->addWidget(queueWidget);

    enqueueButton->setText("Add to Queue");
    connect(enqueueButton, SIGNAL(pressed()),
            this, SLOT(updatePlaylistFromFileDialog()));
    lay->addWidget(enqueueButton);
}

void QueueWindow::updatePlaylistFromFileDialog()
{
    basePlayer->addToPlaylist(QFileDialog::getOpenFileUrl());
    qDebug() << basePlayer->playlist;
}


void QueueWindow::updateQueueDisplay()
{
    qDebug() << Q_FUNC_INFO;

    queueWidget->clear();
    for (auto item : qApp->findChild<Player*>("player")->playlist)
        queueWidget->addItem(item.fileName());
}
