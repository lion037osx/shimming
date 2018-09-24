#include "tableshimming.h"
#include <QDebug>
#include <iostream>

TableShimming::TableShimming(){

}

QString TableShimming::get_measurement(int step){
    static int counter_plane=0;
    static int counter_multi_plane=0;

    QString text_measurement;
    qDebug()<<"Measurement Number: "<<step;

    if(step==0)
    {
        text_measurement= insert_plane(F0BASE);

    }
    if(step==1)
    {
        text_measurement=insert_plane(PLANE_1);
    }

    if(step>=2&&step<=133)
    {
        switch (counter_plane){
        case 0:
            text_measurement=insert_plane(counter_multi_plane+2);
            //text_measurement=insert_index(INDEX_0);
            break;
        case 1:
            text_measurement=insert_index(INDEX_30);
            break;
        case 2:
            text_measurement=insert_index(INDEX_60);
            break;
        case 3:
            text_measurement=insert_index(INDEX_90);
            break;
        case 4:
            text_measurement=insert_index(INDEX_120);
            break;
        case 5:
            text_measurement=insert_index(INDEX_150);
            break;
        case 6:
            text_measurement=insert_index(INDEX_180);
            break;
        case 7:
            text_measurement=insert_index(INDEX_210);
            break;
        case 8:
            text_measurement=insert_index(INDEX_240);
            break;
        case 9:
            text_measurement=insert_index(INDEX_270);
            break;
        case 10:
            text_measurement=insert_index(INDEX_300);
            break;
        case 11:
            text_measurement=insert_index(INDEX_330);
            break;
        default:
            //counter_plane=0;
            break;
    }
        counter_plane++;

        if(counter_plane>=12)
        {
            counter_plane=0;
            counter_multi_plane++;
        }

        if(counter_multi_plane==13){
            counter_multi_plane=0;
        }


    }

    if(step==134)
    {
        text_measurement=insert_plane(PLANE_13);
    }

    if(step==135)
    {
        text_measurement=insert_plane(ISOCENTRO);
    }

    if(step>=136)
    {
        insert_plane(END_MEASURE);
        counter_plane=0;
        counter_multi_plane=0;
    }

    return text_measurement;
}


QString  TableShimming::insert_plane(int plane){
    switch(plane){
    case F0BASE:
        return write_shimming("\r\n\r\nF0 Base Isocentro\t");
        break;
    case PLANE_1:
        return write_shimming("\r\n\r\nPLANO 1\t");
        break;
    case PLANE_2:
        return write_shimming("\r\n\r\nPLANO 2\t");
        break;
    case PLANE_3:
        return write_shimming("\r\n\r\nPLANO 3\t");
        break;
    case PLANE_4:
        return write_shimming("\r\n\r\nPLANO 4\t");
        break;
    case PLANE_5:
        return write_shimming("\r\n\r\nPLANO 5\t");
        break;
    case PLANE_6:
        return write_shimming("\r\n\r\nPLANO 6\t");
        break;
    case PLANE_7:
        return write_shimming("\r\n\r\nPLANO 7\t");
        break;
    case PLANE_8:
        return write_shimming("\r\n\r\nPLANO 8\t");
        break;
    case PLANE_9:
        return write_shimming("\r\n\r\nPLANO 9\t");
        break;
    case PLANE_10:
        return write_shimming("\r\n\r\nPLANO 10\t");
        break;
    case PLANE_11:
        return write_shimming("\r\n\r\nPLANO 11\t");
        break;
    case PLANE_12:
        return write_shimming("\r\n\r\nPLANE 12\t");
        break;
    case PLANE_13:
        return write_shimming("\r\n\r\nPLANE 13\t");
        break;
    case ISOCENTRO:
        return write_shimming("\r\n\r\nISOCENTRO\t");
        break;
    case END_MEASURE:
        return write_shimming("\r\n\r\END MEASURE ");
        break;
    default:
        return write_shimming("\r\n\r\END MEASURE ");
        break;
    }
return write_shimming("\r\n\r\END MEASURE ");
}

QString TableShimming::insert_index(int index){

    switch(index){
//    case INDEX_0:
//        return write_shimming("\t[0°]");
//        break;
//    case INDEX_30:
//        return write_shimming("\t[30°]");
//        break;
//    case INDEX_60:
//        return write_shimming("\t[60°]");
//        break;
//    case INDEX_90:
//        return write_shimming("\t[90°]");
//        break;
//    case INDEX_120:
//        return write_shimming("\t[120°]");
//        break;
//    case INDEX_150:
//        return write_shimming("\t[150°]");
//        break;
//    case INDEX_180:
//        return write_shimming("\t[180°]");
//        break;
//    case INDEX_210:
//        return write_shimming("\t[210°]");
//        break;
//    case INDEX_240:
//        return write_shimming("\t[240°]");
//        break;
//    case INDEX_270:
//        return write_shimming("\t[270°]");
//        break;
//    case INDEX_300:
//        return write_shimming("\t[300°]");
//        break;
//    case INDEX_330:
//        return write_shimming("\t[330°]");
//        break;
    default:
                    return write_shimming("\t");
        break;
    }
            return write_shimming("\t");
}


QString TableShimming::write_shimming(QString txt){
    qDebug()<<txt;

    return ((QString)txt);
}







QString TableShimming::get_plane_angle(int step){
    static int counter_plane=0;
    static int counter_multi_plane=0;

    QString text_measurement;
    qDebug()<<"Measurement Number: "<<step;

    if(step==0)
    {
        text_measurement= "F0 BASE";

    }
    if(step==1)
    {
        text_measurement="PLANE 1 - 0°";
    }

    static int plane = 2;

    if(step>=2&&step<=133)
    {
        switch (counter_plane){
        case 0:
            //text_measurement="insert_plane(counter_multi_plane+2)";
            //text_measurement="PLANE "  plane  "0°";

            text_measurement.sprintf("PLANE %d     0°",plane);

            break;
        case 1:
            //text_measurement="30°";
             text_measurement.sprintf("PLANE %d     30°",plane);
            break;
        case 2:
            //text_measurement="60°";
             text_measurement.sprintf("PLANE %d     60°",plane);
            break;
        case 3:
            //text_measurement="90°";
             text_measurement.sprintf("PLANE %d     90°",plane);
            break;
        case 4:
            //text_measurement="120°";
             text_measurement.sprintf("PLANE %d     120°",plane);
            break;
        case 5:
            //text_measurement="150°";
             text_measurement.sprintf("PLANE %d     150°",plane);

            break;
        case 6:
            //text_measurement="180°";
             text_measurement.sprintf("PLANE %d     180°",plane);
            break;
        case 7:
            //text_measurement="210°";
             text_measurement.sprintf("PLANE %d     210°",plane);
            break;
        case 8:
            //text_measurement="240°";
             text_measurement.sprintf("PLANE %d     240°",plane);
            break;
        case 9:
            //text_measurement="270°";
             text_measurement.sprintf("PLANE %d     270°",plane);
            break;
        case 10:
            //text_measurement="300°";
             text_measurement.sprintf("PLANE %d     300°",plane);
            break;
        case 11:
            //text_measurement="330°";
             text_measurement.sprintf("PLANE %d     330°",plane);
             plane++;
            break;
        default:
            //counter_plane=0;
            break;
    }
        counter_plane++;

        if(counter_plane>=12)
        {
            counter_plane=0;
            counter_multi_plane++;
        }

        if(counter_multi_plane==13){
            counter_multi_plane=0;
        }


    }

    if(step==134)
    {
        text_measurement="PLANE 13 - 0°";
    }

    if(step==135)
    {
        text_measurement="ISOCENTER";
    }

    if(step>=136)
    {
        insert_plane(END_MEASURE);
        counter_plane=0;
        counter_multi_plane=0;
    }

    return text_measurement;
}
