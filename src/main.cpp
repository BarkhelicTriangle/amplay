//#include "playerwindow.h"
#include "playercontrols.h"
#include "player.h"

#include <QApplication>
#include <QGridLayout>
#include <QWindow>

QWidget* createWindow()
{
    QWidget* window = new QWidget();
    QGridLayout* grid = new QGridLayout();

    PlayerControls* controls = new PlayerControls();
    grid->addWidget(controls);

    window->setLayout(grid);
    return window;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Player* player = new Player(&app);
    player->setObjectName("player");

    QWidget* window = createWindow();
    window->show();

    return app.exec();
}
