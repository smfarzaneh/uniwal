#include "random.hpp"

namespace Random {
    double ran1(int &idum) {
        /* 
        This implementation is based on the following paper:
        Sawada, A., & Koga, T. (2017). Physical review e, 95(2), 023309.
        */
        const int IA = 16807;
        const int IM = 2147483647;
        const int IQ = 127773;
        const int IR = 2836; 
        const int NTAB = 32;
        const int NDIV = 1 + (IM - 1) / NTAB;
        const double EPS = 3.0e-16;
        const double AM = 1.0 / IM;
        const double RNMX = 1.0 - EPS;
        static int iy = 0;
        static int iv[NTAB];
        int j, k;
        double temp;
        if (idum <= 0 || !iy) {
            if (-idum < 1)
                idum = 1;
            else 
                idum = -idum;
            for (j = NTAB + 7; j >= 0; j--) {
                k = idum / IQ;
                idum = IA * (idum - k * IQ) - IR * k;
                if (idum < 0)
                    idum += IM;
                if (j < NTAB) 
                    iv[j] = idum;
            }
            iy = iv[0];
        }
        k = idum / IQ;
        idum = IA * (idum - k * IQ) - IR * k;
        if (idum < 0) 
            idum += IM;
        j = iy / NDIV;
        iy = iv[j];
        iv[j] = idum;
        temp = AM * iy;
        if (temp > RNMX) 
            return (float) RNMX;
        else 
            return temp;
    }
}
