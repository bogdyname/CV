#ifndef CRYPTOALGO_H
#define CRYPTOALGO_H

#include <iostream>
#include <algorithm>

class CryptoAlgo
{
    enum Algorithms
    {
        RSA,
        DES,
        AES,
        IDEA
    };


public:
    explicit CryptoAlgo(const float key = 1.0);
    ~CryptoAlgo();

public:
    bool SetAlgorithmToEncrypto(Algorithms algorithm = RSA);
    bool SetAlgorithmToDecrypto(Algorithms algorithm = RSA);

private:
    bool EncryptoRSA();
    bool DecryptoRSA();

    bool EncryptoDES();
    bool DecryptoDES();

    bool EncryptoAES();
    bool DecryptoAES();

    bool EncryptoIDEA();
    bool DecryptoIDEA();

private:
    float key;
};

#endif
