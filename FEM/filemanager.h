#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QSharedPointer>
#include <QDateTime>
#include <QObject>
#include <qqml.h>
#include <QFile>
#include <QDebug>

#include "cryptoalgo.h"

class Filemanager : public QFile
{
    Q_OBJECT
    //QML_ELEMENT
    //Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
    explicit Filemanager(QFile *parent = nullptr, unsigned short int countFiles = 1);
    ~Filemanager();

public slots:
    void LoadFile(const QString& filename);
    void LoadFiles(const QStringList& filenames);

private:
    QSharedPointer<CryptoAlgo> cryptomanager;
};

#endif // FILEMANAGER_H
