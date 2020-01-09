#ifndef ALGORITHMMENU_H
#define ALGORITHMMENU_H

#include <QWidget>
#include <QToolBar>
#include <QMenu>
#include <QApplication>
#include <QDialog>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class AlgorithmMenu; }
QT_END_NAMESPACE

class AlgorithmMenu : public QWidget
{
    Q_OBJECT
public:
    explicit AlgorithmMenu(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::AlgorithmMenu *ui;
};

#endif // ALGORITHMMENU_H
