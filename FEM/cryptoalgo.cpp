#include "cryptoalgo.h"

using namespace std;

CryptoAlgo::CryptoAlgo(const long long firstSeedValue, const long long secondSeedValue)
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

long long CryptoAlgo::SelectFirstSeed(long long value)
{

}

long long CryptoAlgo::SelectSecondSeed(long long value)
{

}

/*-------------------------------MATH--------------------------------*/
bool CryptoAlgo::MillerTest(const long long n)
{
    if(n < 1)
        return false;

    double round = log(n);
}

long long CryptoAlgo::EulersTotientFunction(const long long p, const long long n)
{
    if(p > 1)
        return (pow(p, n) - pow(p, n - 1));
    else
        return p;
}

long long CryptoAlgo::MakePublicKey(const long long value)
{

}

long long CryptoAlgo::MakePrivateKey(const long long value)
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
