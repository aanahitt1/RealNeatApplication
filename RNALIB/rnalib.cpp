
#include "rnalib.h"

RNALIB::RNALIB()
{

}

void RNALIB::stringToFasta (QString str, QString name = "temp"){
    std::string filename = name.toStdString() + ".fasta";
    std::ofstream fOut;
    fOut.open(filename, std::ofstream::out);

    //FASTA must begin with > and then the sequence name
    fOut << ">" << name.toStdString() << std::endl;

    fOut << str.toStdString() << std::endl;

    fOut.close();

    std::cout << "Conversion Complete";
}
