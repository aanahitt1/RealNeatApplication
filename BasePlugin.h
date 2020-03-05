#ifndef BASEPLUGIN_H
#define BASEPLUGIN_H

#include "IAlgorithm.h"
#include <QDir>
#include <QProcess>
#include <QMap>
#include <QJsonDocument>
#include <QObject>
#include <QString>
#include <QJsonArray>
#include <QVariant>
#include <QTemporaryFile>
#include <QTextStream>

class BasePlugin : public IAlgorithm
{
public:
    BasePlugin();
    BasePlugin(QString);
    ~BasePlugin() override;
    QStringList getInfo() override;
    QString getStructure() override;
    QMap<QString,double> getOptions() override;
    QString initiate(QString filepath, QMap<QString, double> opt) override;

    //QProcess* proc;

private:
    void findJson();
    void findDir(QString);
    void extractJsonData();
    QStringList uniteMaps(QMap<QString,double>);
    void buildOptions(QJsonObject);

    QDir* directory;
    QString* path;
    QJsonDocument* doc;
    QProcess* proc;

    QMap<QString,QString> commandMap;

    QStringList info;
    QMap<QString, double> map;
    QString algName;
    QString algDesc;
    QMap<QString, QVariant>* pluginMap;
    QVariantList* algOptions;
    QString structure;

};

#endif // BASEPLUGIN_H
