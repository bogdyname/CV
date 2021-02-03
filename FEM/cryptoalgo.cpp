#include "cryptoalgo.h"

using namespace std;

CryptoAlgo::CryptoAlgo(const float key)
    : key(key)
{
    if(!key)
        this->~CryptoAlgo();
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
