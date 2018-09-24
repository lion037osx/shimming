#ifndef RS232_H
#define RS232_H
#include <qextserialport.h>
#include <QObject>


class RS232 : public QObject
{
        Q_OBJECT
public:
      explicit RS232(QObject *parent = 0);
    ~RS232();


    void putFrecuency();
    bool getConnectSerialPort();

     QextSerialPort *getSerialPort(void);

//private slots:
         int updateReceivedData();
//protected:
         QByteArray bytes_rs232;
private:

    QextSerialPort *serialPortRs232;
    int m_quantity_bytes_send;
    int m_quantity_bytes_received;
    char * rx_data;
     QString buffer;
    void sendComandRs232(QString com);
    QString receivedData;

};

#endif // RS232_H
