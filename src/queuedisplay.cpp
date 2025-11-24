#include "queuedisplay.h"
#include "player.h"
#include <QListWidget>

QueueDisplay::QueueDisplay() : QListWidget()
{
    setViewMode(QListView::ListMode);
    connect(Player::findAppPlayer(), SIGNAL(playlistChanged()),
            this, SLOT(updateQueueDisplay()));
}

void QueueDisplay::updateQueueDisplay()
{
    qDebug() << Q_FUNC_INFO;

    this->clear();
    for (auto item : qApp->findChild<Player*>("player")->playlist)
        addItem(item.toString());
}
