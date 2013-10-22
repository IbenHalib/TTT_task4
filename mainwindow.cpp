#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QPen pen;
    ui->setupUi(this);

    for (int i = 0; i < 5; i++) {
        curve[i] = new QwtPlotCurve;
        curve[i]->attach(ui->qwtPlot);

        // curve->setStyle(QwtPlotCurve::Dots);

        pen.setWidth(2);
        pen.setColor(QColor(0, 10, 200));
        curve[i]->setPen(pen);
    }

    pen.setColor(QColor(0, 10, 200));
    curve[0]->setPen(pen);

    pen.setColor(QColor(200, 20, 0));
    curve[1]->setPen(pen);

    pen.setColor(QColor(30, 100, 0));
    curve[2]->setPen(pen);

    pen.setColor(QColor(0, 0, 0));
    curve[3]->setPen(pen);

    pen.setColor(QColor(100, 100, 0));
    curve[4]->setPen(pen);

    fock = new Focker;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    fock->init();
    vis(0);
    int gr = 1;

//    while (gr < 5) {
//        //     while (true) {
//        int count = 0;

//        // while (count < 10) {

//        QApplication::processEvents();
//        count++;
//        fock->evolute();
//        QApplication::processEvents();
//        //  }

//        if (fock->f[gr*1000][1] > 10) {
//            vis(gr);
//            gr++;
//        }

//    }


    while (true) {
        int count = 0;

        while (count < 100) {

            QApplication::processEvents();
            count++;
            fock->evolute();
            QApplication::processEvents();
        }
        vis(0);


    }

}

void MainWindow::vis(int gr)
{
    vector[gr].clear();

    for (int i = fock->N0; i < N_max; i++)
        vector[gr].append(QPointF(fock->f[i][0], fock->f[i][1]));

    curve[gr]->setSamples(vector[0]);
    ui->qwtPlot->replot();
}
