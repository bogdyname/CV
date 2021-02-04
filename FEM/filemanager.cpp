#include "filemanager.h"

Filemanager::Filemanager(QFile *parent, unsigned short int countFiles)
    : QFile(parent)
{
    //cryptomanager = QSharedPointer<CryptoAlgo>(new CryptoAlgo, &QObject::deleteLater);
}

Filemanager::~Filemanager()
{
    qDebug() << "Filemanager object deleted";
}

void Filemanager::LoadFile(const QString& filename)
{
    if(filename.isEmpty())
        throw "Can't load file: file name is empty";

    QSharedPointer<QFile> file;
    file->setFileName(filename);

    if(file->open(QFile::ReadWrite))
    {

    }
    else
        throw "Can't open file.";

    return;
}

void Filemanager::LoadFiles(const QStringList& filenames)
{
    if(filenames.isEmpty())
        throw "Can't load file: file name is empty";

    QSharedPointer<QFile> file;

    for(const QString& filename: filenames)
    {
        file->setFileName(filename);

        if(file->open(QFile::ReadWrite))
        {

        }
        else
            throw "Can't open file from list of file.";
    }

    return;
}
