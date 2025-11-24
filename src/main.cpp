//#include "playerwindow.h"
#include "playercontrols.h"
#include "player.h"
#include "queuedisplay.h"

#include <QApplication>
#include <QGridLayout>
#include <QWindow>

QWidget* createWindow()
{
    QWidget* window = new QWidget();
    QGridLayout* grid = new QGridLayout();

    PlayerControls* controls = new PlayerControls();
    grid->addWidget(controls, 0,0);

    QueueDisplay* queueDisplay = new QueueDisplay();
    grid->addWidget(queueDisplay, 0,1);

    window->setLayout(grid);

    QObject::connect(qApp, SIGNAL(destroyed()),
                     window, SLOT(deleteLater()));

    return window;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Player* player = new Player();
    player->setParent(&app);

    QWidget* window = createWindow();
    window->show();

    return app.exec();
}
