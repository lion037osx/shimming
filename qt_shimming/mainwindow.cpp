#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QScrollBar>
#include "qextserialenumerator.h"
#include <qextserialport.h>
#include <QTime>
//#include "rs232.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),memberSerialPort(NULL)//,m_serial_port(new MainWindow::RS232)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    memberSerialPort=new RS232(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete memberSerialPort;
}

void MainWindow::on_pushButton_rs232_clicked()
{
    if(memberSerialPort->getConnectSerialPort()){
        ui->pushButton_rs232->setText("Disconnect");
        ui->tabWidget->setCurrentIndex(2);
    }
    else{
        ui->pushButton_rs232->setText("Connect");
    }
}

void MainWindow::on_pushButton_create_file_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    MainWindow::ConfigDate();
    QDateTime UTC(QDateTime::currentDateTimeUtc());
    QDateTime local(UTC.toLocalTime());
QString time_config;


this->name_gemech = "../shimming/data/";
name_gemech+=ui->lineEdit_filename->text();
MainWindow::create_gemech(this->name_gemech );
/*
this->name_gemech_xls = "../shimming/data/";
name_gemech_xls+=ui->lineEdit_filename->text();
name_gemech_xls+=".xls";
MainWindow::create_gemech_xls(this->name_gemech_xls );
*/

ui->plainTextEdit->insertPlainText("\r\n Date :\t");

time_config.setNum( UTC.currentDateTime().date().year()  );
ui->plainTextEdit->insertPlainText( time_config );
ui->plainTextEdit->insertPlainText("/");
time_config.setNum( UTC.currentDateTime().date().month()  );
ui->plainTextEdit->insertPlainText( time_config );
ui->plainTextEdit->insertPlainText("/");
time_config.setNum( UTC.currentDateTime().date().day()  );
ui->plainTextEdit->insertPlainText( time_config );
ui->plainTextEdit->insertPlainText("-");

time_config.setNum( UTC.toLocalTime().time().hour() );

ui->plainTextEdit->insertPlainText( time_config );

ui->plainTextEdit->insertPlainText(":");
//time_config.setNum( (UTC.toTime_t()/60)%60 );
time_config.setNum( UTC.toLocalTime().time().minute());
ui->plainTextEdit->insertPlainText( time_config );

ui->plainTextEdit->insertPlainText("\r\nFile name:\t " + ui->lineEdit_filename->text() + "\r\n" );
ui->plainTextEdit->insertPlainText("Name equipament:\t" + ui->lineEdit_name_equipament->text()+"\r\n" );
ui->plainTextEdit->insertPlainText("Steps:\t" + ui->lineEdit_number_step->text() + "\r\n" );
ui->plainTextEdit->insertPlainText("Temperature Room:\t" + ui->lineEdit_temp_room->text() + "\r\n\r\n" );
ui->plainTextEdit->insertPlainText("Temperature Magnet:\t" + ui->lineEdit_temp_magnet->text() + "\r\n\r\n" );
ui->plainTextEdit->insertPlainText("\r\nINDEX\t0°\t30°\t60°\t90°\t120°\t150°\t180°\t210°\t240°\t270°\t300°\t330°\r\n");

}


void MainWindow::on_pushButton_file_exit_clicked()
{
    MainWindow::CloseFileShimming();
}

void MainWindow::on_pushButton_record_clicked()
{
    static int step=0;
    static bool state=true;
QString value_gemech ;
    /*************************************************************************
                               FUNCTION GET
    *************************************************************************/

            QByteArray frecuency_send=ui->lineEdit_frecuency->text().toLocal8Bit();


            if(frecuency_send.size()==0){
                return;
            }

            ui->label_frecuency->setText(frecuency_send);

            ui->plainTextEdit->insertPlainText(" ");


    if(state){
        QString  measurement;

        measurement =MainWindow::get_measurement(step);

        qDebug()<<"numer steps :"<<step;

  static int value_base;
        step++;
        if(step>=136)
        {


            step=0;
            state=false;

            frecuency_send.resize(8);
            frecuency_send.replace(0,3,"   ");
            int calcule=0;
            calcule=frecuency_send.toInt();
            calcule*=10;
            calcule -= (int)value_base-8000000;
            value_gemech.setNum(calcule);
            MainWindow::record(value_gemech);

        }

        ui->plainTextEdit->insertPlainText(measurement);


        QString get_plane_angle;

        get_plane_angle= MainWindow::get_plane_angle(step);

        ui->label_view_signal->setText(get_plane_angle);



        /**************************************************************************************

          FUNCION PARA INGNORAR EL ULTIMO DIGITO DE LA FRECUENCIA
          ENTRE PLANO 1 Y PLANO 13


        ***************************************************************************************/
//static int value_base;

        if(step==1){
            frecuency_send.resize(9);
            frecuency_send.replace(0,3,"   ");

            value_gemech.setNum( 8000000 + frecuency_send.toInt());
               value_base= frecuency_send.toInt();
               value_base +=8000000;
               QString tmp_fisrt_line="135," + value_gemech;
               MainWindow::record( tmp_fisrt_line);
  //              MainWindow::record_xls(value_gemech,1);
        }


        if(step>=2 && step<=135){

            frecuency_send.resize(8);
            frecuency_send.replace(0,3,"   ");
            int calcule=0;
            calcule=frecuency_send.toInt();
            calcule*=10;
            calcule -= (int)value_base-8000000;
            value_gemech.setNum(calcule);
            MainWindow::record(value_gemech);
        }




        ui->plainTextEdit->insertPlainText(frecuency_send);
         ui->plainTextEdit->insertPlainText(" ");
        ui->plainTextEdit->setCenterOnScroll(1);
        ui->plainTextEdit->centerCursor();
        qDebug()<<"Frecuency : "<<frecuency_send<< "Hz";

/*************************************************************************
                            FUNCTION CLEAR
*************************************************************************/

        ui->lineEdit_frecuency->clear();

/*************************************************************************
                             FUNCTION GET
**************************************************************************/

    }
}

void MainWindow::on_pushButton_get_shim_clicked()
{ 

on_pushButton_cmd_clicked();

onReceivedData();
}


void MainWindow::onReceivedData(){
    QString received_data;

  memberSerialPort->updateReceivedData();
  ui->lineEdit_frecuency->setText(memberSerialPort->bytes_rs232);

}

void MainWindow::on_pushButton_putFrecuency_clicked()
{

}

void MainWindow::on_pushButton_save_clicked()
{
    QString mi_text;
    mi_text=ui->plainTextEdit->toPlainText();
    qDebug()<<mi_text;
    FileShimming::saveFileShimming(mi_text);
}

void MainWindow::on_pushButton_cmd_clicked()
{
    memberSerialPort->putFrecuency();
}

void MainWindow::on_pushButton_back_clicked()
{
        MainWindow::back();
}
