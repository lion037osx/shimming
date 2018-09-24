#ifndef CONFIG_H
#define CONFIG_H

#include "fileshimming.h"

class Config:public FileShimming
{
private:
    char* nameFile;

public:
    Config();
    void ConfigDate();
    void CloseFile();
    void setFileShimming(char*);
};

#endif // CONFIG_H
