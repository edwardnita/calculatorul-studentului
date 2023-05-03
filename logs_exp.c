#include <stdio.h>
#define TOL 0.000001
#define MAXITER 100
#define ln2 0.693147

double Taylor_ln(double x) {
    int i;
    double px = -1, S = 0, Sprev = 100;
    for(i = 1; i < MAXITER; i++) {
        px *= -x;
        S += px/i;
        if(px/i < TOL && px/i > -TOL)
            return S;
    }
    return S;
}

double ln(double arg) {
    int power2 = 0;
    if(arg <= 0){
        // imposibil
        return;
    } else if (arg < 2) {
        //formula este pentru ln(1+x)
        return Taylor_ln(arg - 1);
    } else {
        //vom folosi ln(x) = k*ln2 + ln(x/2^k) 
        while (arg >= 2) {
            arg /= 2;
            power2++;
        }
        return power2 * ln2 +  Taylor_ln(arg - 1);
    }
}

double log(double argument, double base) {
    return ln(argument) / ln(base);
}

double exponential(double exp) {
    // TODO
}

double power(double base, double exp) {
    // TODO
}