#ifndef RNALIB_H
#define RNALIB_H

#include "RNALIB_global.h"
#include <QString>
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>

class RNALIB_EXPORT RNALIB
{
public:
    RNALIB();

    void stringToFasta(QString, QString);
};

#endif // RNALIB_H
