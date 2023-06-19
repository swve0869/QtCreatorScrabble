#ifndef BLANKCREATOR_H
#define BLANKCREATOR_H

#include <QDialog>

namespace Ui {
class blankCreator;
}

class blankCreator : public QDialog
{
    Q_OBJECT

public:
    explicit blankCreator(QWidget *parent = nullptr);
    ~blankCreator();

private:
    Ui::blankCreator *ui;
};

#endif // BLANKCREATOR_H
