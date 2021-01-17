#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QFile>

class Filemanager : public QFile
{
    Q_OBJECT

public:
    explicit Filemanager(QFile *parent = nullptr, unsigned short int countFiles = 1);
    ~Filemanager();

signals:

public slots:
    void LoadFile(const QString& filename);
    void LoadFiles(const QStringList& filenames);

};

#endif // FILEMANAGER_H
