#ifndef IALGORITHM_H
#define IALGORITHM_H

#include <QtPlugin>

class IAlgorithm {

private:
    QString file_path;
    char* options;

public:
    IAlgorithm(QString filepath, char opt[]) {
        file_path = filepath;
        options = opt;
    }

    virtual QString getStructure() = 0;
    virtual QStringList getInfo() = 0;
    virtual QStringList getOptions() = 0;

};

#define IAlgorithm_iid "IAlgorithm"

Q_DECLARE_INTERFACE(IAlgorithm, IAlgorithm_iid);

#endif // IALGORITHM_H
