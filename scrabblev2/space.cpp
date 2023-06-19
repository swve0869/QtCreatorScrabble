#include "space.h"

QRectF Space::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

QPainterPath Space::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}


void Space::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter -> drawPixmap(boundingRect(),sprite,QRectF(0,0,46,46));

    if(state_ <= 0){
        QBrush b = painter->brush();
        painter->setPen(Qt::NoPen);
        painter->setBrush(QBrush(color_));

        painter->drawRect(QRect(this->x_, this->y_, this->width_, this->width_));
        painter->setBrush(b);
    }

}

void Space::mousePressEvent(QGraphicsSceneMouseEvent *event){
    Q_UNUSED(event);

    QString q;
    if(type_ == sType::blank)  {q = "blank";}
    if(type_ == sType::wordM)  {q = "wordM";}
    if(type_ == sType::letterM){q = "letterM";}
    qDebug() << row_ << "  " << col_ << "  " << q;

    emit spaceSelected(this);
}
