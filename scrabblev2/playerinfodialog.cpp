#include "playerinfodialog.h"
#include "ui_playerinfodialog.h"


playerInfoDialog::playerInfoDialog(int n, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playerInfoDialog)
{

    ui->setupUi(this);
    this -> resize(260,n*40 + 20 + 60);

    numP = n;
    int x = 20;
    int y = 30;
    for(int i = 0; i < n; i ++){

        std::string s =  "P" + std::to_string(i+1) + "  Name:";
        QString q(s.c_str());
        QLabel *q_x = new QLabel(q);
        q_x->setParent(this); //this refers to the window/dialog within which this widget will be added/displayed
        q_x->setGeometry(x, y, 60, 20);

        // adding namestuff
        x += 70;

        QTextEdit *qet_x = new QTextEdit();
        qet_x->setGeometry(x, y, 150, 20); //set appropriate values for x_pos, y_pos, height, width
        qet_x->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        qet_x->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        qet_x->setParent(this);
        std::string pt_x_qet = "TextEdit" + std::to_string(i+1); // the name of the widget that you will later use as an identifier to read its value. This should be unique across all widgets in the window/dialog
        qet_x->setObjectName(pt_x_qet.c_str()); // set the identifier of the widget
        names.push_back(qet_x);

        y += 40;
        x = 20;

    }

    QPushButton * start = new QPushButton("Start Game");
    start -> setGeometry(80, y , 100, 40);
    start -> setParent(this);
    QString q("startGameButton");
    start-> setObjectName(q);
    connect(start,&QPushButton::released,this,&playerInfoDialog::startGameSlot);

}

void playerInfoDialog::startGameSlot(){
    std::vector <Player*> players;
    for(int i = 0; i < numP; i++){
        qDebug() << i;
        Player* newP = new Player;
        std::string s = "TextEdit" + std::to_string(i+1);
        QString q = names[i] -> toPlainText();
        newP -> name_ =  q.toStdString();
        newP -> points_ = 0;
        newP -> resigned_ = false;
        players.push_back(newP);
    }

    emit createPlayers(players);
    this -> close();

}


playerInfoDialog::~playerInfoDialog()
{
    delete ui;
}
