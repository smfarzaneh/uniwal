#include "random.hpp"

Random::Random(int initialSeed) {
    if (-initialSeed < 1)
        seed = 1;
    else 
        seed = -initialSeed;
    for (j = NTAB + 7; j >= 0; j--) { // initialize the shuffle table
        k = seed / IQ;
        seed = IA * (seed - k * IQ) - IR * k;
        if (seed < 0)
            seed += IM;
        if (j < NTAB) 
            iv[j] = seed;
    }
    iy = iv[0];
    this->ran1();
}

double Random::ran1() {
    k = seed / IQ;
    seed = IA * (seed - k * IQ) - IR * k;
    if (seed < 0) 
        seed += IM;
    j = iy / NDIV;
    iy = iv[j];
    iv[j] = seed;
    temp = AM * iy;
    if (temp > RNMX) 
        return RNMX;
    else 
        return temp;
}
