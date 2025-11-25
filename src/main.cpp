#include "playercontrols.h"
#include "player.h"
#include "queuewindow.h"

#include <QApplication>

void createWindows()
{
    PlayerControls* controls = new PlayerControls();
    controls->show();

    QueueWindow* queueDisplay = new QueueWindow();
    queueDisplay->show();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qDebug() << qVersion();

    Player* player = new Player();
    player->setParent(&app);

    createWindows();

    return app.exec();
}
