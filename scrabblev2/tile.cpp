#include "tile.h"
#include "qpainter.h"

QRectF Tile::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

QPainterPath Tile::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Tile::print(){
    qDebug() << letter_ << "  " << row_ << " " << col_ << "  " << "x:" << x_ << "  y:" << y_ << "  state:" << state_;
}


void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    painter -> drawPixmap(boundingRect(),sprite,QRectF(0,0,46,46));

    if(state_ == 3){
        QPen pen;

        pen.setColor(Qt::green);
        pen.setWidth(3);

        painter->setPen(pen);
        painter->drawRect(boundingRect());
    }


}

void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event){

    print();
    emit tileSelected(this);
}

