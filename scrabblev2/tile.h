#ifndef TILE_H
#define TILE_H

#include <QObject>
#include <QColor>
#include <QGraphicsItem>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QWidget>


enum tType {letter, blankLetter, bomb};

class Tile : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Tile(int x,int y, int row, int col,int w, int state,QPixmap mp, tType t, char l, int v)
        :x_(x), y_(y),row_(row),col_(col),width_(w),state_(state),sprite(mp),type_(t),letter_(l),value_(v) {}

    int get_x() const { return x_; }  // inline member function
    int get_y() const { return y_; }  // inline member function
    int get_row() const { return row_; }  // inline member function
    int get_col() const { return col_; }  // inline member function
    int get_state() const { return state_; }  // inline member function
    void setXY(int x,int y){x_ = x; y_ = y;}
    void setRC(int r,int c){row_ = r; col_ = c;}
    void setState(int s){state_ = s;}
    void setLetter(char c){letter_ = c;}

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    tType get_type(){return type_;}
    char  get_letter(){return letter_;}
    int   get_value(){return value_;}
    void  print();

private:
    int x_;
    int y_;
    int row_;
    int col_;
    int width_;
    int state_;       // 0 = inPlayer Tiles  1 = onBoard 3 = selected 5 = locked in
    QPixmap sprite;
    enum tType type_;
    char letter_;
    int value_;

signals:
    void tileSelected(Tile* t);

protected:
     void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};


#endif // TILE_H
