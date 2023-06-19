#ifndef OPENDIALOG_H
#define OPENDIALOG_H

#include <QDialog>

namespace Ui {
class openDialog;
}

class openDialog : public QDialog
{
    Q_OBJECT

public:
    explicit openDialog(QWidget *parent = nullptr);
    ~openDialog();

private slots:
    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_clicked();

private:
    Ui::openDialog *ui;


signals:
    void numPlayers(int n);
};

#endif // OPENDIALOG_H
