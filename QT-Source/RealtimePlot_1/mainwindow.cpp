#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Plot_Altitude->addGraph();
    ui->Plot_Altitude->graph(0)->setScatterStyle(QCPScatterStyle::ssCross);
    ui->Plot_Altitude->graph(0)->setLineStyle(QCPGraph::lsNone);
    //ui->plot->graph(0)->setValueAxis(QCPAxis);

    QString GraphName = "Position";
    ui->Plot_Altitude->graph(0)->setName(GraphName);

   // ui->plot->graph(0)->keyAxis->label(GraphName);



    ui->Plot_xyPos->addGraph();
    ui->Plot_xyPos->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->Plot_xyPos->graph(0)->setLineStyle(QCPGraph::lsNone);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::clearData()
{
    vTime.clear();
    vAltitude.clear();
    vCoord_x.clear();
    vCoord_y.clear();
}

void MainWindow::plot()
{
    ui->Plot_Altitude->graph(0)->setData(vTime,vAltitude);
    ui->Plot_xyPos->graph(0)->setData(vCoord_x,vCoord_y);

    ui->Plot_Altitude->replot();
    ui->Plot_xyPos->replot();
    ui->Plot_Altitude->update();
    ui->Plot_xyPos->update();
}


void MainWindow::on_btn_PrPath_clicked()
{
    clearData();
    for (int i=0; i<25; ++i)
    {
    vCoord_x.append(i*0.2);
    vCoord_y.append(i*i*0.01);

    vTime.append(i*0.2);//
    vAltitude.append((i*i*0.002)+1);

    QThread::msleep(100);
    plot();

    }
}

void MainWindow::on_btn_clear_clicked()
{
    clearData();
    plot();

}

void MainWindow::on_btn_Refresh_clicked()
{
clearData();
 for (int i=0; i<25; ++i)
 {
 vCoord_x.append(i*0.2);

  vCoord_y.append(qExp(i*0.01));

 vTime.append(i*0.2);//
 vAltitude.append((i*i*-(0.002))+2);

 QThread::msleep(100);
 plot();

 }

}
