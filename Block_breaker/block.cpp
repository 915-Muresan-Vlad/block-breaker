#include "Block.h"
#include <QBrush>

Block::Block(QGraphicsItem *parent) :
    QGraphicsRectItem(parent)
{
    setRect(0,0,100,25);
    QBrush brush;
    brush.setStyle(Qt::BrushStyle::Dense1Pattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
}

Block::Block(size_t i)
{
    setRect(0,0,100,25);
    QBrush brush;
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    switch (i) {
        case (0):
            brush.setColor(Qt::GlobalColor::red);
            break;
        case (1):
            brush.setColor(Qt::GlobalColor::red);
            break;
        case (2):
            brush.setColor(Qt::GlobalColor::yellow);
            break;
        case (3):
            brush.setColor(Qt::GlobalColor::yellow);
            break;
        case (4):
            brush.setColor(Qt::GlobalColor::blue);
            break;
        case (5):
            brush.setColor(Qt::GlobalColor::blue);
            break;
        case (6):
            brush.setColor(Qt::GlobalColor::green);
            break;
        case (7):
            brush.setColor(Qt::GlobalColor::green);
            break;
    default:
        brush.setColor(Qt::blue);
    }


    setBrush(brush);
}

