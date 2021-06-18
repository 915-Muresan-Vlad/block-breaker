#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Paddle : public QGraphicsRectItem
{

public:
    Paddle(QGraphicsItem* parent = nullptr);

    double getCenterX();

    // events

    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

};

#endif // PADDLE_H
