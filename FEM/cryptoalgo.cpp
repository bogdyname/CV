#include "cryptoalgo.h"

using namespace std;

CryptoAlgo::CryptoAlgo(const float firstSeedValue, const float secondSeedValue)
    : firstSeed(firstSeedValue), secondSeed(secondSeedValue)
{
    if(!firstSeed || !secondSeed)
        this->~CryptoAlgo();

    publicKey = 0x0;
    privateKey = 0x0;
}

CryptoAlgo::~CryptoAlgo()
{
    cout << "CryptoAlgo object deleted" << endl;
}

bool CryptoAlgo::SetAlgorithmToEncrypto(Algorithms algorithm)
{
    switch(algorithm)
    {
        case Algorithms::RSA: EncryptoRSA(); break;
        case Algorithms::DES: EncryptoDES(); break;
        case Algorithms::AES: EncryptoAES(); break;
        case Algorithms::IDEA: EncryptoIDEA(); break;
        default: return false;
    }

    return true;
}

bool CryptoAlgo::SetAlgorithmToDecrypto(Algorithms algorithm)
{
    switch(algorithm)
    {
        case Algorithms::RSA: DecryptoRSA(); break;
        case Algorithms::DES: DecryptoDES(); break;
        case Algorithms::AES: DecryptoAES(); break;
        case Algorithms::IDEA: DecryptoIDEA(); break;
        default: return false;
    }

    return true;
}

float CryptoAlgo::SelectFirstSeed(float value)
{

}

float CryptoAlgo::SelectSecondSeed(float value)
{

}

/*-------------------------------MATH--------------------------------*/
float CryptoAlgo::EulersTotientFunction(const float n)
{
    if(n > 1)
        return (n * 3.14 * (1 - (1 / n)));
    else
        return n;
}

float CryptoAlgo::MakePublicKey(const float value)
{

}

float CryptoAlgo::MakePrivateKey(const float value)
{

}
/*-------------------------------MATH--------------------------------*/

/*--------------------------------RSA--------------------------------*/
bool CryptoAlgo::EncryptoRSA()
{
    return true;
}

bool CryptoAlgo::DecryptoRSA()
{
    return true;
}
/*--------------------------------RSA--------------------------------*/

/*--------------------------------DES--------------------------------*/
bool CryptoAlgo::EncryptoDES()
{
    return true;
}

bool CryptoAlgo::DecryptoDES()
{
    return true;
}
/*--------------------------------DES--------------------------------*/

/*--------------------------------AES--------------------------------*/
bool CryptoAlgo::EncryptoAES()
{
    return true;
}

bool CryptoAlgo::DecryptoAES()
{
    return true;
}
/*--------------------------------AES--------------------------------*/

/*-------------------------------IDEA--------------------------------*/
bool CryptoAlgo::EncryptoIDEA()
{
    return true;
}

bool CryptoAlgo::DecryptoIDEA()
{
    return true;
}
/*-------------------------------IDEA--------------------------------*/
