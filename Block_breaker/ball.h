#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>


class Ball: public QObject,
            public QGraphicsEllipseItem
{
    Q_OBJECT

public:
    double xSpeed;
    double ySpeed;
    Ball(QGraphicsItem* parent = nullptr);

    double getCenterX();

public slots:

    void move();

private:
    void reverse_speed();   // daca trece de margini
    void PaddleCollision(); // coliziunea cu paleta
    void BlockCollision();  // coliziunea cu blocurile
};

#endif // BALL_H
