//#include "playerwindow.h"
#include "playercontrols.h"
#include "player.h"

#include <QApplication>
#include <QGridLayout>
#include <QWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Player* player = new Player(&app);
    player->setObjectName("player");

    //Initialize window (should be its own function)
    QWidget* win = new QWidget;
    QGridLayout* lay = new QGridLayout;

    PlayerControls controls;
    lay->addWidget(&controls);

    win->setLayout(lay);
    win->show();
    return app.exec();
}
