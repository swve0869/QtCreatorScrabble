#ifndef PLAYERINFODIALOG_H
#define PLAYERINFODIALOG_H

#include <QLabel>
#include <QTextEdit>
#include <string>
#include <QDial>
#include <QDialog>
#include <QPainter>
#include <QPushButton>
#include "tile.h"


struct Player {
    std::string name_;
    int points_;
    QColor color_;
    std::vector<Tile*> pTiles_;
    bool resigned_;
};

namespace Ui {
class playerInfoDialog;
}

class playerInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit playerInfoDialog(int n, QWidget *parent = nullptr);
    ~playerInfoDialog();

signals:
    void createPlayers(std::vector<Player*>);


protected slots:
    void startGameSlot();

private:
    Ui::playerInfoDialog *ui;
    int numP;
    std::vector<QTextEdit*> names;
    std::vector<QColor*> colors;


};

#endif // PLAYERINFODIALOG_H
