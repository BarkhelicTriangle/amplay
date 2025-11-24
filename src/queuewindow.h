#ifndef QUEUEWINDOW_H
#define QUEUEWINDOW_H

#include "player.h"

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class QueueWindow : public QWidget
{
    Q_OBJECT
private:
    Player* basePlayer = Player::findAppPlayer();
public:
    QueueWindow();
    QVBoxLayout* lay = new QVBoxLayout(this);
    QListWidget* queueWidget = new QListWidget(this);
    QPushButton* enqueueButton = new QPushButton(this);

public slots:
    void updateQueueDisplay();
    void updatePlaylistFromFileDialog();
};

#endif // QUEUEWINDOW_H
