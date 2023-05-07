#include <stdio.h>
#define TOL 0.0000001
#define MAXITER 100
#define ln2 0.693147
#define APROX(x) ((x) + 5 * TOL)

double Taylor_ln(double x) {
    int i;
    double px = -1, S = 0, Sprev = 100;
    for(i = 1; i < MAXITER; i++) {
        px *= -x;
        S += px/i;
        if(px/i < TOL && px/i > -TOL)
            return APROX(S);
    }
    return APROX(S);
}

double ln(double arg, int *imposibil) {
    int power2 = 0;

    *imposibil = 1;
    if(arg <= 0){
        // imposibil
        *imposibil = 0;
        return 0;
    } else if (arg < 2) {
        //formula este pentru ln(1+x)
        return APROX(Taylor_ln(arg - 1));
    } else {
        //vom folosi ln(x) = k*ln2 + ln(x/2^k) 
        while (arg >= 2) {
            arg /= 2;
            power2++;
        }
        return APROX(power2 * ln2 +  Taylor_ln(arg - 1));
    }
}

double logarithm(double argument, double base, int *imposibil) {
    return APROX(ln(argument, imposibil) / ln(base, imposibil));
}

double exponential(double exp) {
    double px = 1, S = 1;
    int i;
    for(i = 1; i < MAXITER; i++) {
        px *= exp/i;
        S += px;
        if(px < TOL && px > -TOL)
            return APROX(S);
    }
    return APROX(S);
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

double power(double base, double exp, int *imposibil) {
    int nat;
    double real, e;
    if(exp < 0){
        base = 1 / base;
        exp = -exp;
    }
    nat = (int)exp;
    real = exp - (double)nat;
    // conditie oprire
    if (base < 0 && (real >= TOL && real <= -TOL)) {
        *imposibil = 0;
        return 0;
    } else if (base < 0) {
        e = 0;
    } else {
        e = real * ln(base, imposibil);
    }
    *imposibil = 1;
    return APROX(exponential(e) * natural_power(base, nat));
}