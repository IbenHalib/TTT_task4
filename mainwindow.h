#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qwt_plot_curve.h>
#include <QVector>
#include <QPointF>
#include "focker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QwtPlotCurve *curve[5];
    QVector<QPointF> vector[5];
    Focker *fock;
    void vis(int gr);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
