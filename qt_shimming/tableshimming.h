#ifndef TABLESHIMMING_H
#define TABLESHIMMING_H

#include <QDebug>

typedef enum {
F0BASE,
PLANE_1,
PLANE_2,
PLANE_3,
PLANE_4,
PLANE_5,
PLANE_6,
PLANE_7,
PLANE_8,
PLANE_9,
PLANE_10,
PLANE_11,
PLANE_12,
PLANE_13,
ISOCENTRO,
END_MEASURE
}PLANE;

typedef enum {
INDEX_0,
INDEX_30,
INDEX_60,
INDEX_90,
INDEX_120,
INDEX_150,
INDEX_180,
INDEX_210,
INDEX_240,
INDEX_270,
INDEX_300,
INDEX_330
}INDEX_GRADE;




class TableShimming
{
public:
    TableShimming();
    QString get_measurement(int);
    QString insert_index(int);
    QString insert_plane(int);
    QString write_shimming(QString);
    QString get_plane_angle(int);

};

#endif // TABLESHIMMING_H
