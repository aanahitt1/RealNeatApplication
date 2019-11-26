#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createFileBar();
    setWindowTitle("Real Neat Application");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createFileBar()
{
    QAction *quit = new QAction("&Quit", this);

    QMenu *FileBar;
    FileBar = menuBar()->addMenu("&File");
    FileBar->addAction(quit);

    connect(quit, &QAction::triggered, qApp, QApplication::quit);

}
