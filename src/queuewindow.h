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
    QVBoxLayout* lay = new QVBoxLayout(this);
public:
    QueueWindow();
    QListWidget* queueWidget = new QListWidget(this);
    QPushButton* enqueueButton = new QPushButton(this);

public slots:
    void updateQueueDisplay();
    void updateQueueFromFileDialog();
};

#endif // QUEUEWINDOW_H
