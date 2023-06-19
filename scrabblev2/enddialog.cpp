#include "enddialog.h"
#include "ui_enddialog.h"

endDialog::endDialog(std::vector<Player*> players, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::endDialog)
{
    ui->setupUi(this);

    int amt = players.size();
    this -> resize(260,amt*50+100);
    int x = 50; int y = 50;

    for(unsigned long i = 0; i < players.size(); i ++){

        std::string s =  players[i] -> name_ + " : " + std::to_string(players[i] -> points_);
        QString q(s.c_str());
        QLabel *q_x = new QLabel(q);
        q_x->setParent(this); //this refers to the window/dialog within which this widget will be added/displayed
        q_x->setGeometry(x, y, 80, 20);
        y+= 50;

    }

}

endDialog::~endDialog()
{
    delete ui;
}
