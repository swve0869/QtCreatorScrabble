#include "blankcreator.h"
#include "ui_blankcreator.h"

blankCreator::blankCreator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::blankCreator)
{
    ui->setupUi(this);
}

blankCreator::~blankCreator()
{
    delete ui;
}
