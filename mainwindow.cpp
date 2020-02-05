#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    file_path = "";
    algoList = NULL;
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
      QAction* Algorithms = new QAction("&Algorithms", this);

      //Creating menu
      QMenu *FileBar;
      FileBar = menuBar()->addMenu("&File");
      FileBar->addAction(Algorithms);
      FileBar->addAction(quit);

      connect(quit, &QAction::triggered, qApp, QApplication::quit);

      QDialog* listDialog = createAlgoList();

      connect(Algorithms, &QAction::triggered, listDialog, &QDialog::show);

}

QDialog* MainWindow::createAlgoList() {

    //Create the dialog window so it looks good.
    QDialog* list = new QDialog();
    list->resize(500, 300);
    QGridLayout* back = new QGridLayout(list);
    algoList = new QListWidget();
    QPushButton* ok = new QPushButton("&OK");
    QLabel* description = new QLabel();
    description->setWordWrap(true);
    back->cellRect(3, 2);
    back->setColumnMinimumWidth(2, 250);
    back->setRowMinimumHeight(1, 25);
    back->setRowMinimumHeight(2, 150);
    back->setRowMinimumHeight(3, 25);
    back->addWidget(new QLabel("Algorithms"), 1, 1);
    back->addWidget(algoList, 2, 1);
    back->addWidget(ok, 3, 1);
    back->addWidget(description, 2, 2);

    connect(ok, &QPushButton::clicked, list, &QDialog::hide);

    ParseXML* gopher = new ParseXML();
    QString* names = gopher->getInfo("C:\\Users\\Anahit\\Documents\\RealNeatApplication\\Config.xml", "name");
    QString* desc = gopher->getInfo("C:\\Users\\Anahit\\Documents\\RealNeatApplication\\Config.xml", "desc");

    //Populate list
    int i =0;
    while(names[i] != "NON") {
        algoList->addItem(names[i]);
        QListWidgetItem* item = algoList->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        i++;
    }

    connect(algoList, &QListWidget::itemPressed, [=](QListWidgetItem* item) {on_listItem_changed(item, description, names, desc);});

    return list;
}

void MainWindow::on_listItem_changed(QListWidgetItem* list, QLabel* description, QString* names, QString* desc) {

    int i = 0;
    while(names[i] != "NON") {
        if(names[i] == list->text()) {
            description->setText(desc[i]);
        }
        i++;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString sequence = QInputDialog::getText(this, "Sequence", "Insert RNA sequencce: ");
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
    //Set file_path to wherever we save it.
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open Sequence", "C:\\documents", "Text files (*.txt);;FASTA files (*.FASTA)");
    if(filename.contains(".txt")) {
        //turn it into a FASTA file
        //Save it somewhere
        //Set file_path to where we saved it.
    } else {
        file_path = filename;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(file_path == "") {
        QMessageBox error;
        error.critical(this, "ERROR", "No sequence chosen.");
        return;
    }
    QList<int>* checked = new QList<int>();
    for (int i = 0; i < algoList->count(); i++) {
        if(algoList->item(i)->checkState() == Qt::Checked) {
            checked->append(i);
        }
    }
    if(checked->isEmpty()) {
        QMessageBox error;
        error.critical(this, "ERROR", "No algorithms chosen.");
        return;
    }

}
