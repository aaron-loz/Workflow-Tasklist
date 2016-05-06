#include "settitledialog.h"
#include "ui_settitledialog.h"

setTitleDialog::setTitleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setTitleDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("Set Title"));
}

setTitleDialog::~setTitleDialog()
{
    delete ui;
}

void setTitleDialog::setvalue()
{
    newTitle= ui->lineEdit->text();
}

void setTitleDialog::on_buttonBox_accepted()
{
    setvalue();
}
