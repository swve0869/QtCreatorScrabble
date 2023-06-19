#include "blankcreater.h"
#include "ui_blankcreater.h"

blankCreater::blankCreater(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::blankCreater)
{
    ui->setupUi(this);
}

blankCreater::~blankCreater()
{
    delete ui;
}

void blankCreater::on_pushButton_clicked()
{
    QString q = ui -> textEdit -> text();
    q.toUpper();
    if(q.length() == 1 ){
        std::string s = q.toStdString();
        char c = toupper(s[0]);
        emit blankSubmit(c);
        this -> close();
    }

}

