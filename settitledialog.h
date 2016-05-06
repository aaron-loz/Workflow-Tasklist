#ifndef SETTITLEDIALOG_H
#define SETTITLEDIALOG_H

#include <QDialog>

namespace Ui {
class setTitleDialog;
}

class setTitleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setTitleDialog(QWidget *parent = 0);
    ~setTitleDialog();
    QString newTitle;
private slots:
    void on_buttonBox_accepted();
    void setvalue();
private:
    Ui::setTitleDialog *ui;
};

#endif // SETTITLEDIALOG_H
