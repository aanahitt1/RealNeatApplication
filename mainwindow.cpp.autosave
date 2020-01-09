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
    QAction *algWindow = new QAction("&Algorithms", this);

    QMenu *FileBar;
    FileBar = menuBar()->addMenu("&File");
    FileBar->addAction(algWindow);

    connect(algWindow, &QAction::triggered, this, &MainWindow::algorithmsMenu);

}

void MainWindow::algorithmsMenu(){
    QListWidget* algMenu = new QListWidget();
    algMenu->setVisible(true);
    algMenu->setWindowTitle("Select An Algorithm");

   ParseXML* myparser = new ParseXML();
   QStringList* list = myparser->getNames("Config.xml");
   QStringList* commands = new QStringList({"DAFS", "PhyloFold", "RNA Fold", "S-Fold", "RNA Structure"});
   QStringList myworkinglist = *commands;
   algMenu->addItems(myworkinglist);
   algMenu->show();
}

void MainWindow::commandChanged(){

}
