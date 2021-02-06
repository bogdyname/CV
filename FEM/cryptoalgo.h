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
    explicit CryptoAlgo(const float firstSeedValue = 1.0, const float secondSeedValue = 1.0);
    ~CryptoAlgo();

public:
    bool SetAlgorithmToEncrypto(Algorithms algorithm = RSA);
    bool SetAlgorithmToDecrypto(Algorithms algorithm = RSA);

//random
private:
    float SelectFirstSeed(float value = 1.0);
    float SelectSecondSeed(float value = 1.0);

//math
protected:
    float EulersTotientFunction(float x = 1.0);

//algorithms
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
    float firstSeed;
    float secondSeed;
};

#endif
