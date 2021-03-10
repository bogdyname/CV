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

bool CryptoAlgo::EncryptoRSA()
{
    return true;
}

bool CryptoAlgo::DecryptoRSA()
{
    return true;
}
