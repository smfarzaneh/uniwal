#ifndef RANDOM_HPP
#define RANDOM_HPP

class Random {
    static const int IA = 16807;
    static const int IM = 2147483647;
    static const int IQ = 127773;
    static const int IR = 2836; 
    static const int NTAB = 32;
    static const int NDIV = 1 + (IM - 1) / NTAB;
    static constexpr double EPS = 3.0e-16;
    static constexpr double AM = 1.0 / IM;
    static constexpr double RNMX = 1.0 - EPS;
    int iy = 0;
    int iv[NTAB];
    int j, k;
    double temp;
    public:
        int seed;
        Random(int initialSeed);
        double ran1();
};

#endif // RANDOM_HPP
