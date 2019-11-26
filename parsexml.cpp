#include "parsexml.h"
// Library needed for processing XML documents
#include <QtXml>
// Library needed for processing files
#include <QFile>
#include <QString>

ParseXML::ParseXML()
{
    class ParseXML {
    public:
        //This function will return a string of names from an XML document
        QString* getNames(QString FileName) {
            //The QDomDocument class represents an XML document.
            QDomDocument xmlBOM;
            // Load xml file as raw data
            QFile f(FileName);
            if (!f.open(QIODevice::ReadOnly ))
            {
                // Error while loading file
                QString *error = new QString();
                QString message = "Error while loading file.";
                error[0] = message;
                return error;
            }
            // Set data into the QDomDocument before processing
            xmlBOM.setContent(&f);
            f.close();

            //Find the names and store them
            QDomElement program = xmlBOM.documentElement().firstChild().toElement();
            QString* names = new QString();
            int i = 0;

            while(!program.isNull()) {
                if(program.tagName() == "Program") {
                    QString name = program.attribute("name");
                    names[i] = name;
                    i++;
                }
            }

            return names;

        }

    };

}
