#include "parsexml.h"

ParseXML::ParseXML(){
}
        QStringList* ParseXML::getNames(QString FileName) {
            //The QDomDocument class represents an XML document.
            QDomDocument xmlBOM;
            // Load xml file as raw data
            QFile f(FileName);
            if (!f.open(QIODevice::ReadOnly | QIODevice::Text ))
            {
                // Error while loading file
                QStringList* error = new QStringList();
                QString message = "Error while loading file.";
                error->append(message);
                return error;
            }
            // Set data into the QDomDocument before processing
            xmlBOM.setContent(&f);
            f.close();

            //Find the names and store them
            QDomElement program = xmlBOM.documentElement().firstChild().toElement();
            QStringList* names = new QStringList();
            int i = 0;

            while(!program.isNull()) {
                if(program.tagName() == "Program") {
                    QString name = program.attribute("name");
                    names->append(name);
                    i++;
                }
            }

            return names;

        }

        //This function will return a string of descriptions from an XML document
        QString* ParseXML::getDescriptions(QString FileName) {
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
                    QString name = program.attribute("desc");
                    names[i] = name;
                    i++;
                }
            }

            return names;

        }




