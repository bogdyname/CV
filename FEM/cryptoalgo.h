#ifndef CRYPTOALGO_H
#define CRYPTOALGO_H

#include <QObject>

class CryptoAlgo : public QObject
{
    Q_OBJECT
public:
    explicit CryptoAlgo(QObject *parent = nullptr);

signals:

};

#endif // CRYPTOALGO_H
