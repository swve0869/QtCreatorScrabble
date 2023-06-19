#ifndef BLANKCREATER_H
#define BLANKCREATER_H

#include <QDialog>

namespace Ui {
class blankCreater;
}

class blankCreater : public QDialog
{
    Q_OBJECT

public:
    explicit blankCreater(QWidget *parent = nullptr);
    ~blankCreater();

private slots:
    void on_pushButton_clicked();

signals:
void blankSubmit(char let);

private:
    Ui::blankCreater *ui;
};

#endif // BLANKCREATER_H
