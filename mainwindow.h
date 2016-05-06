#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addtaskdialog.h"
#include "settitledialog.h"
namespace Ui {
class TaskList;
}

class TaskList : public QMainWindow
{
    Q_OBJECT

public:
    explicit TaskList(QWidget *parent = 0);
    ~TaskList();
private slots:
    void Exit();
    void Open();
    void Save();
    void on_clearButton_clicked();
    void on_actionAddTask_triggered();

    void on_lineEdit0_returnPressed();
    void on_lineEdit1_returnPressed();
    void on_lineEdit2_returnPressed();
    void on_lineEdit3_returnPressed();
    void on_lineEdit4_returnPressed();
    void on_lineEdit5_returnPressed();
    void on_lineEdit6_returnPressed();
    void on_lineEdit7_returnPressed();
    void on_lineEdit8_returnPressed();
    void on_lineEdit9_returnPressed();
    void on_lineEdit10_returnPressed();
    void on_lineEdit11_returnPressed();
    void on_lineEdit12_returnPressed();
    void on_lineEdit13_returnPressed();
    void on_lineEdit14_returnPressed();
    void on_lineEdit15_returnPressed();
    void on_lineEdit16_returnPressed();
    void on_lineEdit17_returnPressed();
    void on_lineEdit18_returnPressed();
    void on_lineEdit19_returnPressed();

    void on_actionSet_WorkFlow_Title_triggered();

public slots:
    void setEdit();
private:
    Ui::TaskList *ui;
    void createMenus();
    void startupBox();
    void setTitle();
    addtaskdialog *AddTaskDialog;
    setTitleDialog *TitleDialog;
    QMenu *fileMenu;
    QAction *exitAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *addTaskAct;
};

#endif // MAINWINDOW_H
