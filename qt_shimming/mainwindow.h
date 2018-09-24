#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "config.h"
#include "tableshimming.h"
#include "rs232.h"
#include <qextserialport.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow,TableShimming,FileShimming
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_rs232_clicked();

    void on_pushButton_create_file_clicked();

    void on_pushButton_file_exit_clicked();

    void on_pushButton_record_clicked();

    void on_pushButton_get_shim_clicked();

    void onReceivedData();

    void on_pushButton_putFrecuency_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_cmd_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::MainWindow *ui;
    RS232 *memberSerialPort;
    QString name_gemech;
    QString name_gemech_xls;
    int step;
    bool state;
};

#endif // MAINWINDOW_H
