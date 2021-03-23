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

void Filemanager::LoadFiles(const QStringList& filenames)
{
    if(filenames.isEmpty())
        return;

    QFile file;

    for(const QString& filename: filenames)
    {
        file.setFileName(filename);

        if(file.open(QFile::ReadWrite))
        {


            file.close();
        }
        else
        {
            file.close();
            break;
        }
    }

    return;
}
