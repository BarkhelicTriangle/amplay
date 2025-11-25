#include "queuewindow.h"
#include "player.h"
#include <QListWidget>
#include <QFileDialog>

QueueWindow::QueueWindow() : QWidget()
{
    setWindowTitle("amplay QueueWindow");
    this->basePlayer = Player::findAppPlayer();
    this->lay = new QVBoxLayout(this);

    this->queueWidget = new QListWidget(this);
    queueWidget->setViewMode(QListView::ListMode);
    connect(Player::findAppPlayer(), SIGNAL(playlistChanged()), this, SLOT(updateQueueDisplay()));
    lay->addWidget(queueWidget);

    this->enqueueButton = new QPushButton(this);
    enqueueButton->setText("Add to Queue");
    connect(enqueueButton, SIGNAL(pressed()), this, SLOT(updateQueueFromFileDialog()));
    lay->addWidget(enqueueButton);
}

void QueueWindow::updateQueueFromFileDialog()
{
    qDebug() << Q_FUNC_INFO;
    auto newSongs = QFileDialog::getOpenFileUrls();
    for (auto song : newSongs)
        basePlayer->addToQueue(song);
    qDebug() << basePlayer->queue;
}

void QueueWindow::updateQueueDisplay()
{
    qDebug() << Q_FUNC_INFO;

    queueWidget->clear();
    for (QUrl item : qApp->findChild<Player*>("player")->queue)
        queueWidget->addItem(item.fileName());
}
