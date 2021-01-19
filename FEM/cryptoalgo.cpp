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
        default: return false; break;
    }
}

bool CryptoAlgo::SetAlgorithmToDecrypto(Algorithms algorithm)
{
    switch(algorithm)
    {
        case Algorithms::RSA: DecryptoRSA(); break;
        case Algorithms::DES: DecryptoDES(); break;
        case Algorithms::AES: DecryptoAES(); break;
        case Algorithms::IDEA: DecryptoIDEA(); break;
        default: return false; break;
    }
}

/*--------------------------------RSA--------------------------------*/
bool CryptoAlgo::EncryptoRSA()
{

}

bool CryptoAlgo::DecryptoRSA()
{

}
/*--------------------------------RSA--------------------------------*/

/*--------------------------------DES--------------------------------*/
bool CryptoAlgo::EncryptoDES()
{

}

bool CryptoAlgo::DecryptoDES()
{

}
/*--------------------------------DES--------------------------------*/

/*--------------------------------AES--------------------------------*/
bool CryptoAlgo::EncryptoAES()
{

}

bool CryptoAlgo::DecryptoAES()
{

}
/*--------------------------------AES--------------------------------*/

/*-------------------------------IDEA--------------------------------*/
bool CryptoAlgo::EncryptoIDEA()
{

}

bool CryptoAlgo::DecryptoIDEA()
{

}
/*-------------------------------IDEA--------------------------------*/
