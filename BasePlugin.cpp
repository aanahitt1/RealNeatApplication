#include "IAlgorithm.h"
#include "BasePlugin.h"
#include <QObject>
#include <QProcess>
#include <QString>
#include <QJsonArray>
#include <QVariant>

#ifdef Q_OS_WINDOWS
#define MYEXPORT __declspec(dllexport)
#else
#define MYEXPORT
#endif

Q_PLUGIN_METADATA(IAlgorithm_IID FILE BasePlugin.json)
Q_INTERFACES(IAlgorithm)

BasePlugin::BasePlugin(){
    //placeholder, generalization needed
    initiate("RNAfold.exe", {"--noPS"});
}

BasePlugin::BasePlugin(QJsonObject ini){
    QString str = "options";

    //ini is the entirety of the .json file for this plugin
    //It can be converted into a QVariantMap
     pluginMap = new QVariantMap(ini.toVariantMap());
    //Supposedly a QVariantMap is "Synonym for QMap<QString, QVariant>."
    //Whatever that means...
     //from pluginMap, which is declared as QMap<QString,QVariant>, we should be able to extract values by using
     //pluginMap->value()/pluginMap->key() to return the QVariant/QString
     //this however, returns a const object. which we can't assign to anything
     //instead we have to do this

     //To-do: Initialize using total number of unique options for each plugin
     QString commandArr[50];
     //QStringList optionArr[50];

     QVariant var;
     var = pluginMap->value("options");

     QSequentialIterable itrVar = var.value<QSequentialIterable>();

     int i = 0;
     for(const QVariant &v : itrVar){
        QMap<QString,QVariant> tempMap;
        tempMap = v.toMap();
        commandArr[i] = tempMap.value("command").toString();
        map.unite(tempMap.value("pass").value<QMap<QString,double>>());
     }
}

void BasePlugin::initiate(QString filepath, QStringList opt){
    file_path = filepath;
   // proc = new QProcess(this);

}

QString BasePlugin::getStructure(){
    return structure;
}
QStringList BasePlugin::getInfo(){
    return info;
}
QMap<QString,double> BasePlugin::getOptions(){
    return map;
}

BasePlugin::~BasePlugin(){
    delete pluginMap;
    delete algOptions;
}

extern "C" MYEXPORT IAlgorithm* create_RNAfoldPlugin() {
    return new BasePlugin();
}
