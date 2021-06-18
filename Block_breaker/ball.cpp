#include "Ball.h"
#include <QTimer>
#include <QBrush>
#include <QMessageBox>
#include "Game.h"
#include "Paddle.h"
#include "Block.h"

extern Game* game;

Ball::Ball(QGraphicsItem *parent) :
    QObject(),
    QGraphicsEllipseItem(parent)

{
    setRect(0, 0, 30, 30);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

    // porneste in sus din start
    xSpeed = 0;
    ySpeed = -8;

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(16);

}


double Ball::getCenterX()
{
    return x() + rect().width()/2;

}

void Ball::move()
{

        // daca trece peste margini se inveseaza vitezele
        reverse_speed();

        // la ciocnirea cu paleta (paddle) , viteza pe y se invereaza si viteza pe x creste
        // depinzand unde pe axa x loveste
        PaddleCollision();

        // la coliziuni cu un block , sterge block ul si se inverseaza viteze
        BlockCollision();

        moveBy(xSpeed,ySpeed);

}

void Ball::reverse_speed()
{

    double screenW = game->scene->width();
    double screenH = game->height();
    // verific daca
    // marginea stanga
    if (mapToScene(rect().topLeft()).x() <= 0){
        xSpeed = -xSpeed;
    }

    // marginea dreapta
    if (mapToScene(rect().topRight()).x() >= screenW){
        rect().setRight(screenW);
        xSpeed = -xSpeed;
    }

    // margine superioara
    if (mapToScene(rect().topLeft()).y() <= 0){
        ySpeed = -ySpeed;
    }

    // la marginea inferioara nu verific <=> mingea poate sa cada si daca cade e game over
    if (mapToScene(rect().topLeft()).y() > screenH){

        ySpeed = 0;
        xSpeed = 0;

        game->GameOver();

    }

}

void Ball::PaddleCollision()
{
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i)
    {
        Paddle* paddle = dynamic_cast<Paddle*>(cItems[i]);
        if (paddle)
        {
            // la ciocnire cu placa
            // inversez viteza pe axa y
            ySpeed = -ySpeed;

            // viteza pe x din functie de locul unde loveste
            double ballX = getCenterX();
            double paddleX = paddle->getCenterX();

            double dvx = ballX - paddleX;
            xSpeed = (xSpeed + dvx)/16;

            return;
        }
    }
}

void Ball::BlockCollision()
{
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i)
    {
        Block* block = dynamic_cast<Block*>(cItems[i]);

        if (block)              // daca se ciocneste cu un block
        {
            double yPad = 15;
            double xPad = 15;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = block->pos().x();
            double blocky = block->pos().y();

            game->score++;
            // ciocnire de jos
            if (bally > blocky + yPad && ySpeed < 0){
                ySpeed = -ySpeed;
            }

            // ciocneste de deasupra
            if (blocky > bally + yPad && ySpeed > 0 ){
                ySpeed = -ySpeed;
            }

            // ciocneste din dreapta
            if (ballx > blockx + xPad && xSpeed < 0){
                xSpeed = -xSpeed;
            }

            // ciocneste din stanga
            if (blockx > ballx + xPad && xSpeed > 0){
                xSpeed = -1 * xSpeed;
            }

            // Sterg block-ul ciocnit
                game->scene->removeItem(block);
                delete block;
                n--;

            game->changeScore();
        }
    }
}
