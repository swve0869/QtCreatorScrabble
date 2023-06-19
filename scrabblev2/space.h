#ifndef SPACE_H
#define SPACE_H

#include <QObject>
#include <QColor>
#include <QGraphicsItem>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include <cstring>

enum sType {blank, letterM, wordM, pTileBlank};

class Space : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Space(int x,int y, int row, int col,int w, int state,QColor c,QPixmap mp, sType b, int m)
        :x_(x), y_(y),row_(row),col_(col),width_(w),state_(state),color_(c),sprite(mp), type_(b),multiplier_(m){}

    int get_multiplier(){return multiplier_;}
    int get_x() const { return x_; }  // inline member function
    int get_y() const { return y_; }  // inline member function
    int get_row() const { return row_; }  // inline member function
    int get_col() const { return col_; }  // inline member function
    int get_state() const { return state_; }  // inline member function
    sType get_type() const {return type_;}
    void setXY(int x,int y){x_ = x; y_ = y;}
    void setRC(int r,int c){row_ = r; col_ = c;}

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

private:
    int x_;
    int y_;
    int row_;
    int col_;
    int width_;
    int state_;
    QColor color_;
    QPixmap sprite;
    sType type_;
    int multiplier_;

signals:
     void spaceSelected(Space*s);

protected:
     void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // SPACE_H
