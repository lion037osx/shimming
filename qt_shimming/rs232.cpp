#include "rs232.h"
#include "qextserialenumerator.h"
#include <QDebug>
#include <iostream>

namespace myNamespace {

};

//using myNamespace;

RS232::RS232(QObject *parent) :
    QObject(parent),serialPortRs232(NULL)
{

}

RS232::~RS232(){

delete serialPortRs232;

}

int RS232::updateReceivedData(){
    QByteArray bytes;
    int counter_rs232=serialPortRs232->bytesAvailable();

    //if(bytes.isNull())return;
    bytes.resize(counter_rs232);

    serialPortRs232->read(bytes.data(),bytes.size());
    m_quantity_bytes_received+=counter_rs232;

    //this->receivedData+=bytes;

    qDebug()<<"count"<<counter_rs232;
    if (counter_rs232>=10)
    {
        //qDebug()<<"received data"<<this->receivedData;
        qDebug()<<"bytes"<<bytes;

        char str_tmp[10];

       // strcpy(str_tmp , bytes);



//
//        this->bytes_rs232=str_tmp;

        bytes.resize(9);
        qDebug()<<"bytes.rezize"<<bytes;

   //     bytes.resize(8);
 //       bytes.insert(8,"0");
    //    qDebug()<<"bytes.rezize + insert 0 "<<bytes;
      //  bytes.insert(0, ' ');

        this->bytes_rs232=bytes;


        //this->receivedData.clear();
       // return this->receivedData.capacity();
    }
    return 0x00;


/*
    QByteArray bytes;
    int cant=m_port->bytesAvailable();
    //if(bytes.isNull())return;
    bytes.resize(cant);
    m_port->read(bytes.data(),bytes.size());//cant de datos a leer
    m_cant_bytes_recibidos+=cant;
    //ui->textEdit->insertPlainText(bytes);
    ui->lineEdit_Recibidos->setText(QString::number(m_cant_bytes_recibidos));
    ui->lineEdit_receive_data->insertPlainText(bytes);
    ui->lineEdit_receive_data->ensureCursorVisible();

    if(stat==1){
        QTextStream stream( &file );
        stream<<bytes;
    }
    if(cant>=10){cant=0;
         qDebug()<<"dDebug:"<<bytes;

    }
  */


}



bool RS232::getConnectSerialPort(){

     if (!serialPortRs232)
     {
         QString sPort;
         serialPortRs232= new QextSerialPort(sPort, QextSerialPort::EventDriven);
         serialPortRs232->setBaudRate(BAUD9600);
         serialPortRs232->setFlowControl(FLOW_OFF);
         serialPortRs232->setParity(PAR_NONE);
         serialPortRs232->setDataBits(DATA_8);
         serialPortRs232->setStopBits(STOP_1);

         //m_port->setPortName("/dev/cu.SLAB_USBtoUART");
         serialPortRs232->setPortName("/dev/ttyUSB0");


         if(serialPortRs232->open(QIODevice::ReadWrite)==true)
         {
              qDebug()<<"Open Port";

              connect(serialPortRs232, SIGNAL(readyRead()),this,SLOT (updateReceivedData()));


         }
         else
         {
             qDebug()<<"Openning error";
             delete serialPortRs232; // libero memoria dinamica
             serialPortRs232=NULL;
         }
     }
     else
     {
         qDebug()<<"Close Port";
         delete serialPortRs232;
         serialPortRs232=NULL;
     }
     if (serialPortRs232 && serialPortRs232->isOpen())
         return true;
     else
         return false;

}


 void RS232::putFrecuency(){
     static int frecuency=8540001;

QByteArray myString;
myString.setNum(frecuency);
char str_command_ready_teslameter=0x05;

myString.append(str_command_ready_teslameter);
     serialPortRs232->write(myString);
//serialPortRs232->write();


     frecuency++;
     return;
 }

 QextSerialPort *RS232::getSerialPort(){
return serialPortRs232;
 }


