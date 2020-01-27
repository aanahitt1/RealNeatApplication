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
    //QAction* Algorithms = new QAction("&Algorithms", this);

    QMenu *FileBar;
    FileBar = menuBar()->addMenu("&File");
    //FileBar->addAction(Algorithms);
    FileBar->addAction(quit);

    QListWidget* algoList = new QListWidget(this);

    connect(quit, &QAction::triggered, qApp, QApplication::quit);

    ParseXML* gopher = new ParseXML();
    QString* names = gopher->getInfo("C:\\Users\\Anahit\\Documents\\RealNeatApplication\\Config.xml", "name");
    //QString* desc = gopher->getInfo("C:\\Users\\Anahit\\Documents\\RealNeatApplication\\Config.xml", "desc");

    int i =0;
    while(names[i] != "NON") {
        algoList->addItem(names[i]);
        i++;
    }

    //connect(Algorithms, &QAction::triggered, algoList);

}

void MainWindow::on_pushButton_clicked()
{
    QString sequence = QInputDialog::getText(this, "Sequence", "Insert RNA sequence: ");
    sequence = sequence.toUpper();
    int i = 0;
    while(sequence[i]!=NULL) {
        if(sequence[i]!='A' && sequence[i]!='C' && sequence[i]!='U' && sequence[i]!='G') {
            QMessageBox error;
            error.critical(this, "ERROR", "This is not a valid RNA sequence");
            error.setVisible(true);
            break;
        }
        i++;
    }
    //Turn the string into a FASTA file
    //Pass the FASTA file to our algorithm
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open Sequence", "C:\\documents", "Text files (*.txt);;FASTA files (*.FASTA)");
    if(filename.contains(".txt")) {
        //turn it into a FASTA file
    }
    //Pass the FASTA file to the algorithm.
}
