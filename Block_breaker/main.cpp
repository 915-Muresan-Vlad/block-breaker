#include "game.h"
#include "ui_game.h"

#include <QApplication>

Game* game;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    //game->Start();

    return a.exec();
}
