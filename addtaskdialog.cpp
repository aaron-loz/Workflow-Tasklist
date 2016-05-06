#include "addtaskdialog.h"
#include "ui_addtaskdialog.h"

addtaskdialog::addtaskdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addtaskdialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("Add the Task!"));
}

addtaskdialog::~addtaskdialog()
{
    delete ui;
}

void addtaskdialog::on_addtaskdialog_accepted()
{
    QString str = ui->lineEdit->text();
    setText(str);
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
    //add a line that puts focus back to lineEdit
}

void addtaskdialog::on_addtaskdialog_rejected()
{
    foreach(QLineEdit *lineEdit, this->findChildren<QLineEdit*>()) {
        lineEdit->clear();
    }
}

void addtaskdialog::setText(QString &text)
{
    value = text;
}
