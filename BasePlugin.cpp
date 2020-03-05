#include "BasePlugin.h"

#ifdef Q_OS_WINDOWS
#define MYEXPORT __declspec(dllexport)
#else
#define MYEXPORT
#endif

Q_PLUGIN_METADATA(IAlgorithm_IID FILE BasePlugin.json)
Q_INTERFACES(IAlgorithm)

BasePlugin::BasePlugin(){
    //placeholder, generalization needed
    //initiate("RNAfold.exe", );
}

BasePlugin::BasePlugin(QString path){

    findDir(path);
    findJson();
    extractJsonData();
}

//From a filepath with the .exe location and a list of options, construct and pass a command line argument.
QString BasePlugin::initiate(QString filepath, QMap<QString, double> opt){
    file_path = filepath;
    proc = new QProcess(NULL);

    QStringList args = uniteMaps(opt);

    args << "-i " + filepath;

    //@To-do:
    //Set up check for exe location
    proc->setProgram("RNAfold.exe");
    proc->setArguments(args);

    proc->start();
    proc->waitForFinished();
    structure = proc->readAllStandardOutput();
    QString err = proc->readAllStandardError();

    return structure;
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

void BasePlugin::findDir(QString _path){
    this->path = &_path;
    QString lib = "..\\lib\\";
    QString defPath = lib + path;
    directory = new QDir(*path);

    if(!directory->exists()){
        //We haven't been passed a complete path
        //Attempt to find it
        directory = new QDir(defPath);
    }else if(!directory->exists()){
        qWarning("Cannot find directory");
    }
}

void BasePlugin::findJson(){
    QString fileName = *path + ".json";
    QStringList filters;
    filters << fileName;
    directory->setNameFilters(filters);

    QStringList file;
    if((file = directory->entryList(filters)).isEmpty()){
        qWarning("Cannot find plugin");
    }
    doc = new QJsonDocument(QJsonDocument::fromJson(file.first().toLocal8Bit()));

}

//Extracts the plugin details and creates the objects to send to the user interface.
void BasePlugin::extractJsonData(){
    pluginMap = new QVariantMap(doc->object().toVariantMap());

    QVariant var;
    var = pluginMap->value("options");

    QSequentialIterable itrVar = var.value<QSequentialIterable>();

    //Assemble a map of Keys:Commands and a map of Keys:default values.
    for(const QVariant &v : itrVar){
       QMap<QString,QVariant> tempMap;
       tempMap = v.toMap();
       QString tempVal = tempMap.value("command").toString();
       QMap<QString,double> tempKV = tempMap.value("pass").value<QMap<QString,double>>();
       commandMap.insert(tempKV.firstKey(),tempVal);
       map.unite(tempMap.value("pass").value<QMap<QString,double>>());
    }

}

//Creates the QStringList of arguments which will be used to run the process.
QStringList BasePlugin::uniteMaps(QMap<QString,double> usrOpts){
    QStringList args;
    QString comm;
    double val;
    QString argument;
    for(auto k : usrOpts.keys()){
        comm = commandMap.value(k);
        if(usrOpts.value(k) != 0.0){
            val = usrOpts.value(k);
            args << comm + " " + val;
        }else{
            args << comm;
        }
    }
    return args;
}

BasePlugin::~BasePlugin(){
    delete pluginMap;
    delete algOptions;
}

extern "C" MYEXPORT IAlgorithm* create_RNAfoldPlugin() {
    return new BasePlugin();
}
