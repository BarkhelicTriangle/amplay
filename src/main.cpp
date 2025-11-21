#include "playerwindow.h"
#include "player.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Player* player = new Player(&app);
    player->setObjectName("player");

    PlayerWindow window;
    window.show();

    return app.exec();
}
