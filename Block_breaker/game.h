#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <paddle.h>
#include <ball.h>

namespace Ui {
class Game;
}

class Game : public QGraphicsView
{
    Q_OBJECT

public:

    explicit Game(QWidget *parent = nullptr);
    ~Game();

    QGraphicsScene* scene;
    Paddle *paddle;
    Ball *ball;
    int score = 0;              // scorul = numarul de blocuri sparte


    void Start();
    void GameOver();
    void createBlockCol(double x);
    void createBlockGrid();
    void changeScore();

public slots:
    void restart();

private slots:
    void on_startbtn_clicked();

    void on_InfoBtn_clicked();

    void on_ExitBtn_clicked();

    void on_TryAgainbtn_clicked();

private:
    Ui::Game *ui;

};

#endif // GAME_H
