#ifndef BASEPLUGIN_H
#define BASEPLUGIN_H

#include "IAlgorithm.h"
#include <QProcess>
#include <QMap>

class BasePlugin : public IAlgorithm
{
public:
    BasePlugin();
    BasePlugin(QJsonObject);
    ~BasePlugin() override;
    QStringList getInfo() override;
    QString getStructure() override;
    QMap<QString,double> getOptions() override;
    void initiate(QString filepath, QStringList opt) override;

    //QProcess* proc;

private:
    void buildOptions(QJsonObject);
    QStringList info;
    QMap<QString, double> map;
    QString algName;
    QString algDesc;
    QMap<QString, QVariant>* pluginMap;
    QVariantList* algOptions;
    QString structure;

};

#endif // BASEPLUGIN_H
