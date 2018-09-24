#include "config.h"
#include <QByteArray>
#include <QDate>
#include <QTime>
#include <QDebug>



Config::Config()
{

}

void Config::ConfigDate()
{

    static int *year=new int ;
    static int *mon=new int ;
    static int *day=new int ;
    static int *hour=new int ;
    static int *min=new int ;
    static int *sec=new int ;

    QDateTime UTC(QDateTime::currentDateTimeUtc());
    QDateTime local(UTC.toLocalTime());
    char txt[45];
    time_t  time=UTC.toTime_t();
    time=time-10800;
    *year=(UTC.toTime_t()/31556926);
    *sec=time%60;
    *min=(time/60)%60;
    *hour=(time/3600)%24;
    *day=(time/(3600*24))%31;
    *mon=(((time-(time/31556926)))/2629743%12)+1;
    sprintf(txt,"log%d%02d%02d%02d%02d%02d.txt",(*year+1970),*mon,*day,*hour,*min,*sec);
    qDebug()<<txt;
    Config::setFileShimming(txt);


}

void Config::setFileShimming(char * txt){

this->nameFile=txt;

}


void Config::CloseFile(){

 //Config::CloseFileShimming();
   //  qDebug()<<"previo al cierre";
}
