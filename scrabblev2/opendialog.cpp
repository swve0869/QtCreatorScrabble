#include "opendialog.h"
#include "ui_opendialog.h"

openDialog::openDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::openDialog)
{
    ui->setupUi(this);
}

openDialog::~openDialog()
{
    delete ui;
}

void openDialog::on_twoButton_clicked()
{
    emit numPlayers(2);
    this -> close();

}


void openDialog::on_threeButton_clicked()
{
    emit numPlayers(3);
    this -> close();

}


void openDialog::on_fourButton_clicked()
{
    emit numPlayers(4);
    this -> close();

}

