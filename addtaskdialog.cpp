#include "addtaskdialog.h"
#include "mainwindow.h"
#include "ui_addtaskdialog.h"
#include "ui_addtaskdialog.h"
#include <QDebug>

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
    qDebug()<<"pressed okay";
    QString str = ui->lineEdit->text();
    setText(str);
    qDebug()<<str;
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
    //add a line that puts focus back to lineEdit
}

void addtaskdialog::on_addtaskdialog_rejected()
{
    qDebug()<<"pressed Cancel";
    foreach(QLineEdit *lineEdit, this->findChildren<QLineEdit*>()) {
        lineEdit->clear();
    }
}

void addtaskdialog::setText(QString &text)
{
    value = text;
}
