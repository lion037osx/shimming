#include "fileshimming.h"
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QDate>
#include <QTime>


FileShimming::FileShimming()
{
}


void FileShimming::setFileShimming(char * namefileshimming){
    file.setFileName(namefileshimming);

        if ( file.open(QIODevice::ReadWrite) )
            {
            qDebug()<<" file.open(QIODevice::ReadWrite) ";
            this->stat=true;
            }
        else{
            qDebug()<<"ERROR file";
            file.close();
            }
}


void FileShimming::create_gemech(QString name_gemech_00x_x){
    fs_gemech.setFileName(name_gemech_00x_x);

        if ( fs_gemech.open(QIODevice::ReadWrite) )
            {
            qDebug()<<" file.open(QIODevice::ReadWrite) ";
            this->stat=true;
            }
        else{
            qDebug()<<"ERROR file";
            fs_gemech.close();
            }
}



void FileShimming::create_gemech_xls(QString name_gemech_00x_x_xls){
    fs_gemech.setFileName(name_gemech_00x_x_xls);

        if ( fs_gemech_xls.open(QIODevice::ReadWrite) )
            {
            qDebug()<<" file.open(QIODevice::ReadWrite) ";
            this->stat=true;
            }
        else{
            qDebug()<<"ERROR file";
            fs_gemech_xls.close();
            }
}


void FileShimming::CloseFileShimming()
{
    file.close();
    fs_gemech.close();
    fs_gemech_xls.close();


    qDebug()<<"file.close()";
}


void FileShimming::record(QString frecuency)
{
    QTextStream stream( &fs_gemech );
    stream<<frecuency<<"\r\n";
    qDebug()<<"function record ";
}

void FileShimming::record_xls(QString frecuency,int i)
{

    QTextStream stream( &fs_gemech_xls );
    stream<<frecuency<<"\t"<<"=A"<<i<<"- A1"<<"\r\n";
}


void FileShimming::saveFileShimming(QString bytes)
{
    QTextStream stream( &file );
    stream<<bytes;
}


void FileShimming::ConfigDate()
{

     int *year=new int ;
     int *mon=new int ;
     int *day=new int ;
     int *hour=new int ;
     int *min=new int ;
     int *sec=new int ;

    QDateTime UTC(QDateTime::currentDateTimeUtc());
    QDateTime local(UTC.toLocalTime());
    char txt[45];
    time_t  time=UTC.toTime_t();
    time=time-10800;
    *year=(UTC.toTime_t()/31556926);
    *sec=time%60;
    *min=(time/60)%60;
    *hour=(time/3600)%24;
    *day=UTC.currentDateTime().date().day();
    *mon=(((time-(time/31556926)))/2629743%12)+1;

    sprintf(txt,"../shimming/data/gemech_001_v_shim_log_%d%02d%02d%02d%02d.xls",(*year+1970),*mon,*day,*hour,*min);
    qDebug()<<txt;
    setFileShimming(txt);

}

void FileShimming::back(){
    QTextStream stream( &fs_gemech );
    stream<<"\t UNDO\r\n";
}

