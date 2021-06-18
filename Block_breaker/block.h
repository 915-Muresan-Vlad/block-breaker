#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsRectItem>

class Block: public QGraphicsRectItem{
public:

    Block(QGraphicsItem* parent = nullptr);
    Block(size_t i);
};


#endif // BLOCK_H
