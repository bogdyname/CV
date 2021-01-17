#include "filemanager.h"

Filemanager::Filemanager(QFile *parent, unsigned short int countFiles)
    : QFile(parent)
{
    if(countFiles > 1)
    {

    }
    else
    {

    }
}

Filemanager::~Filemanager()
{

}

void Filemanager::LoadFile(const QString& filename)
{

    return;
}

void Filemanager::LoadFiles(const QStringList& filenames)
{

    return;
}
