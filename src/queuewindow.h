#pragma once

#include "player.h"

#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class QueueWindow : public QWidget
{
    Q_OBJECT
private:
    Player* basePlayer = nullptr;
    QVBoxLayout* lay = nullptr;
public:
    QueueWindow();
    QListWidget* queueWidget = nullptr;
    QPushButton* enqueueButton = nullptr;

public slots:
    void updateQueueDisplay();
    void updateQueueFromFileDialog();
};
