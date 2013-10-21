#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    curve = new QwtPlotCurve;
    curve->attach(ui->qwtPlot);


    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(0, 10, 200));
    curve->setPen(pen);

    fuck = new Fucker;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    fuck->init();
    vis();

    while (true) {
        int count = 0;

        while (count < 100) {
            fuck->evolute();
            QApplication::processEvents();
            count++;
        }
        vis();
        QApplication::processEvents();
    }

}

void MainWindow::vis()
{
    vector.clear();

    for (int i = fuck->N0; i < N_max; i++)
        vector.append(QPointF(fuck->f[i][0], fuck->f[i][1]));

    curve->setSamples(vector);
    ui->qwtPlot->replot();
}
