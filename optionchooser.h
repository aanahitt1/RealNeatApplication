#ifndef OPTIONCHOOSER_H
#define OPTIONCHOOSER_H

#include <QObject>
#include <QWidget>
#include <QListWidget>
#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <QMapIterator>
#include <QInputDialog>
#include <QMessageBox>

class OptionChooser : public QObject
{
private:
    QMap<QString, QVariant> options;
    QListWidget* optList;
    QDialog* main;

public:
    OptionChooser(QMap<QString, QVariant> opt);

    void getNumber(QListWidgetItem* item);
    void show();

signals:
   void boxClosed(QString opt);
};

#endif // OPTIONCHOOSER_H
