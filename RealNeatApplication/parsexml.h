#ifndef PARSEXML_H
#define PARSEXML_H
#include <QtXml> // Library needed for processing files
#include <QFile> // Library needed for processing XML documents
#include <QString>
#include <QStringList>

class ParseXML
{
public:
    ParseXML();
    QStringList* getNames(QString);
    QString* getDescriptions(QString);

};

#endif // PARSEXML_H
