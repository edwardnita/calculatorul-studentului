#include <stdio.h>
#define TOL 0.00000001
#define MAXITER 1000
#define APROX(x) ((x) + 5 * TOL * 10)
#define CHECK_TOL(x) ((x) < TOL && (x) > -TOL)
#define MIN 0.0001
#define CHECK_APROX(x) ((x) < MIN && (x) > -MIN)

double sinus(double x) {
    double px = x, S = x;
    int i;
    for(i = 1; i < MAXITER; i++) {
        px *= -x*x/(2 * i * (2 * i + 1));
        S += px;
        if(CHECK_TOL(px)) 
            return APROX(S);
    }
    return APROX(S);
}

double cosinus(double x) {
    double px = 1, S = 1;
    int i;
    for(i = 1; i < MAXITER; i++) {
        px *= -x*x/((2 * i - 1) * 2 * i);
        S += px;
        if(CHECK_TOL(px))
            return APROX(S);
    }
    return APROX(S);
}

double tangent(double x, int *imposibil) {
    double c;
    c = cosinus(x);
    *imposibil = 1;
    if(!CHECK_APROX(c)) { 
        return APROX(sinus(x) / c);
    } else {
        *imposibil = 0;
        return 0;
    }
}

double cotangent(double x, int *imposibil) {
    double s;
    s = sinus(x);
    *imposibil = 1;
    if(!CHECK_APROX(s)) {
        return APROX(cosinus(x) / s);
    } else {
        *imposibil = 0;
        return 0;
    }
}