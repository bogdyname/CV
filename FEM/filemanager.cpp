#include "filemanager.h"

Filemanager::Filemanager(QFile *parent, unsigned short int countFiles)
    : QFile(parent)
{
    cryptomanager = QSharedPointer<CryptoAlgo>(new CryptoAlgo, &QObject::deleteLater);
}

Filemanager::~Filemanager()
{

}

void Filemanager::LoadFile(const QString& filename)
{
    if(filename.isEmpty())
        throw "Can't load file: file name is empty";


    return;
}

void Filemanager::LoadFiles(const QStringList& filenames)
{
    if(filenames.isEmpty())
        throw "Can't load file: file name is empty";


    return;
}
