#ifndef FILESHIMMING_H
#define FILESHIMMING_H
#include <QFile>


class FileShimming
{
private:
    QFile file;
    QFile fs_gemech;
    QFile fs_gemech_xls;
    char nameFileShimming[40];
    bool checked;
    bool stat;

public:
    FileShimming();
    void setFileShimming(char *);
    void CloseFileShimming();
    void saveFileShimming(QString);
        void ConfigDate();
        void create_gemech(QString);
        void create_gemech_xls(QString);
        void record_xls(QString,int);
        void record(QString);
        void back();
};

#endif // FILESHIMMING_H
