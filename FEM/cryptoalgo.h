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
    explicit CryptoAlgo(const float firstSeedValue = 0x1p-1022, const float secondSeedValue = 0x1.ffffffffffp+1023);
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
    float EulersTotientFunction(const float x = 1.0);
    float MakePublicKey(const float value = 0x47867f);
    float MakePrivateKey(const float value = 0x76874f);

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
    float publicKey;
    float privateKey;
};

#endif
