#include "playercontrols.h"
#include "player.h"
#include "queuedisplay.h"

#include <QApplication>
#include <QGridLayout>
#include <QWindow>

void createWindows()
{
    PlayerControls* controls = new PlayerControls();
    controls->setWindowTitle("amplay PlayerControls");
    controls->show();

    QueueDisplay* queueDisplay = new QueueDisplay();
    queueDisplay->setWindowTitle("amplay QueueDisplay");
    queueDisplay->show();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qDebug() << qVersion();

    Player* player = new Player();
    player->setParent(&app);

    createWindows();
   // window->show();

    return app.exec();
}
