#ifndef QUEUEDISPLAY_H
#define QUEUEDISPLAY_H

#include <QListWidget>
#include <QLabel>

class QueueDisplay : public QListWidget
{
    Q_OBJECT
public:
    QueueDisplay();

public slots:
    void updateQueueDisplay();
};

#endif // QUEUEDISPLAY_H
