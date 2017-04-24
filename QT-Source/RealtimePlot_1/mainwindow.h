#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void clearData();
    void plot();

private slots:


    void on_btn_clear_clicked();



    void on_btn_Refresh_clicked();

    void on_btn_PrPath_clicked();

private:
    Ui::MainWindow *ui;

    QVector<double> vTime, vAltitude;
    QVector<double> vCoord_x, vCoord_y;

};

#endif // MAINWINDOW_H
