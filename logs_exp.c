#include <stdio.h>
#define TOL 0.0000001
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

double logarithm(double argument, double base) {
    return ln(argument) / ln(base);
}

double exponential(double exp) {
    double px = 1, S = 1;
    int i;
    for(i = 1; i < MAXITER; i++) {
        px *= exp/i;
        S += px;
        if(px < TOL && px > -TOL)
            return S;
    }
    return S;
}

// functia de putere cu exponent natural
double natural_power(double base, int exp) {
    double pow;
    if (exp != 0) {
        pow = natural_power(base, exp/2);
    } else {
        return 1;
    }
    if (exp & 1 == 1) {
        return base * pow *pow;
    } else {
        return pow * pow;
    }
}

double power(double base, double exp) {
    int nat;
    double real, e;
    if(exp < 0){
        base = 1 / base;
        exp = -exp;
    }
    nat = (int)exp;
    real = exp - (double)nat;
    e = real * ln(base);
    return exponential(e) * natural_power(base, nat);
}