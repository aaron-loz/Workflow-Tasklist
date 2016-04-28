#include "mainwindow.h"
#include "ui_tasklist.h"
#include "addtaskdialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QAction>
#include <string>
TaskList::TaskList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TaskList)
{
    AddTaskDialog = new addtaskdialog;//SWITCH THESE SO IT IS addTaskDialog = new AddTaskDialog. Involves multiple lines changed !
    ui->setupUi(this);
    createMenus();
    setWindowTitle(tr("Task List!"));
    startupBox();
    foreach(QAbstractButton *checkbtn, this->findChildren<QAbstractButton*>()) {
        checkbtn->setFocusPolicy(Qt::NoFocus);//this makes the tab key skip over checkboxesw
    }
}

TaskList::~TaskList()
{
    delete ui;
}


void TaskList::createMenus()
{    //first menu
    fileMenu = menuBar()->addMenu(tr("&File"));

    //!0
    openAct = new QAction(tr("O&pen"), this);
    fileMenu ->addAction(openAct);
    connect(openAct, &QAction::triggered, this, &TaskList::Open);
    //!1
    saveAct = new QAction(tr("S&ave..."), this);
    fileMenu ->addAction(saveAct);
    connect(saveAct, &QAction::triggered, this, &TaskList::Save);
    //!2
    exitAct = new QAction(tr("E&xit"), this);
    fileMenu->addAction(exitAct);
    connect(exitAct, &QAction::triggered, this, &TaskList::Exit);
    //!3
}

void TaskList::startupBox()
{//when the window opens, it will ask this question.
    QMessageBox::StandardButton startup;
    startup = QMessageBox::question(this, "Startup?", "Would you like to start adding tasks right away?",
                                      QMessageBox::Yes | QMessageBox::No);
    switch(startup){
    case QMessageBox::Yes:
        on_actionAddTask_triggered();
        break;
    case QMessageBox::No:
        break;
    default:
        break;
    }
}

void TaskList::Exit() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit", "Quit?",
                                  QMessageBox::Yes | QMessageBox::No);
    switch(reply)
    {
    case QMessageBox::Yes:
        qDebug()<<"Yes was Clicked";
        QCoreApplication::exit();
    break;
    default:
        qDebug()<<"No was Clicked";
    break;
    }
}

void TaskList::on_clearButton_clicked()
{//removes all text from editlines
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
    foreach(QAbstractButton *checkbtn, this->findChildren<QAbstractButton*>()) {
        checkbtn->setChecked(false);
    }
}

void TaskList::setEdit()
{
    QString str;//by assigning str to the public value, it gets around issues of different cpp files interacting.
    str =AddTaskDialog->value;
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>())
    {
        if(widget->text().isEmpty())
        {//checks if the line is empty before adding the text
            widget->setText(str);
            break;
        }
    }
}



//Activate once taskWidget.h and taskWidget.cpp created
void TaskList::Open()
{
/*    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
        tasksWidget->readFromFile(fileName);
*/}

void TaskList::Save()
{/*
    QString fileName = QFileDialog::getSaveFileName(this);
    if(!fileName.isEmpty())
        taskWidget->writeToFile(fileName);
*/}



void TaskList::on_actionAddTask_triggered()
{
    AddTaskDialog->setModal(true);
    for(int i=0; i<20;i++)
    {
        if(AddTaskDialog->exec())
        {
//when you press okay, this set edit will go because it is set
            setEdit();// from the ok button
        }
        else
        {
           break;
        }
    }
}

void TaskList::on_lineEdit0_returnPressed()
{
    if(ui->checkBox->isChecked()){
        ui->checkBox->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit1_returnPressed()
{
    if(ui->checkBox_2->isChecked()){
        ui->checkBox_2->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_2->setCheckState(Qt::Checked);
    }
}
//next time think of using like a new EditLineText when the addtask is added
void TaskList::on_lineEdit2_returnPressed()
{
    if(ui->checkBox_7->isChecked()){
        ui->checkBox_7->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_7->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit3_returnPressed()
{
    if(ui->checkBox_8->isChecked()){
        ui->checkBox_8->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_8->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit4_returnPressed()
{
    if(ui->checkBox_3->isChecked()){
        ui->checkBox_3->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_3->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit5_returnPressed()
{
    if(ui->checkBox_9->isChecked()){
        ui->checkBox_9->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_9->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit6_returnPressed()
{
    if(ui->checkBox_10->isChecked()){
        ui->checkBox_10->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_10->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit7_returnPressed()
{
    if(ui->checkBox_11->isChecked()){
        ui->checkBox_11->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_11->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit8_returnPressed()
{
    if(ui->checkBox_4->isChecked()){
        ui->checkBox_4->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_4->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit9_returnPressed()
{
    if(ui->checkBox_12->isChecked()){
        ui->checkBox_12->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_12->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit10_returnPressed()
{
    if(ui->checkBox_13->isChecked()){
        ui->checkBox_13->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_13->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit11_returnPressed()
{
    if(ui->checkBox_14->isChecked()){
        ui->checkBox_14->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_14->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit12_returnPressed()
{
    if(ui->checkBox_5->isChecked()){
        ui->checkBox_5->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_5->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit13_returnPressed()
{
    if(ui->checkBox_15->isChecked()){
        ui->checkBox_15->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_15->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit14_returnPressed()
{
    if(ui->checkBox_16->isChecked()){
        ui->checkBox_16->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_16->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit15_returnPressed()
{
    if(ui->checkBox_17->isChecked()){
        ui->checkBox_17->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_17->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit16_returnPressed()
{
    if(ui->checkBox_6->isChecked()){
        ui->checkBox_6->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_6->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit17_returnPressed()
{
    if(ui->checkBox_18->isChecked()){
        ui->checkBox_18->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_18->setCheckState(Qt::Checked);

    }
}

void TaskList::on_lineEdit18_returnPressed()
{
    if(ui->checkBox_19->isChecked()){
        ui->checkBox_19->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_19->setCheckState(Qt::Checked);

    }
}
void TaskList::on_lineEdit19_returnPressed()
{
    if(ui->checkBox_20->isChecked()){
        ui->checkBox_20->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_20->setCheckState(Qt::Checked);
    }
}
