#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QMenu>
#include <QApplication>
#include <QDialog>
#include <QComboBox>
#include <QListWidget>
#include "parsexml.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void algorithmsMenu();
    void commandChanged();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    void createFileBar();


};
#endif // MAINWINDOW_H
